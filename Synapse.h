#pragma once
#include "ComponentProvider.h"
#include "System.h"
#include <stack>
#include <vector>
#include <algorithm>
#include <shared_mutex>
#include <thread>
#include <atomic>
namespace CompoT{
    class Synapse{
    private:
        ComponentProvider &provider;
        std::vector<std::shared_ptr<System>> systems;
        std::stack<System*> jobs;
        std::shared_mutex jobMutex;
        std::vector<std::thread> threads;
        class ThreadCode{
        private:
            Synapse &parent;
        public:
            System* job;
            std::mutex jobMutex;
            std::atomic<bool> isInterrupted;
            ThreadCode(Synapse &parent):parent(parent), job(nullptr), isInterrupted(false){}
            void run(){
                while(!isInterrupted){
                    std::unique_lock<std::mutex> lock(jobMutex);
                    //
                    if(job == nullptr){
                        lock.unlock();
                        std::this_thread::yield();
                    }else{
                        job->run(parent.provider.getComponentsForType(job->getTargetType()));
                        job = nullptr;
                        lock.unlock();
                    }
                    
                    //
                }
                
            }
        };
        std::vector<std::shared_ptr<ThreadCode>> codes;
    public:
        Synapse(ComponentProvider &provider)
        :provider(provider){
            int numThreads = std::thread::hardware_concurrency();
            numThreads = numThreads - 2;
            if(numThreads <= 0){
                numThreads = 2;
            }

            for(int i = 0; i < numThreads;i++){
                this->codes.emplace_back(std::make_shared<ThreadCode>(*this));
                this->threads.emplace_back(&ThreadCode::run, this->codes.at(i));
            }
        }
       void add(System *system){
            for(auto & sys : systems){
                if(sys->getTargetType() == system->getTargetType())
                    throw std::runtime_error("System for type already exists");
            }
            systems.emplace_back(system);
        }
        void remove(const System &system){
            for(int i = 0 ; i < this->systems.size(); i++){
                if((*this->systems.at(i)) == system){
                    this->systems.erase(this->systems.begin()+i);
                    break;
                }
            }
        }

        void execute(){
            std::shared_lock<std::shared_mutex> jobLock(this->jobMutex, std::defer_lock);
            ///populate jobs
            jobLock.lock();
            if(jobs.size() > 0){
                throw std::runtime_error("JOBS UNFINISHED");
            }
            for(auto & system : systems){
                jobs.push(&*system);
            }
            {
                
                int i = 0;
                while(!jobs.empty()){
                    auto &code = codes.at(i);
                    std::unique_lock<std::mutex> lock(code->jobMutex);
                    if(code->job == nullptr){
                        code->job = jobs.top();
                        jobs.pop();
                    }
                    lock.unlock();
                    
                    i++;
                    i = i % codes.size();
                }
            }
            jobLock.unlock();
            ///
        }
        virtual ~Synapse(){
            for(auto &code : this->codes)
                code->isInterrupted = true;
            for(auto &thread : this->threads){
                thread.join();
            }
        }
    };

}