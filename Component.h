#pragma once
#include <mutex>
namespace CompoT{
    class Component{
    private:
        std::mutex mutex;
    public:
        template<typename T>
        T* get(){
            return dynamic_cast<T*>(this);
        }
        virtual ~Component(){}
    };
}