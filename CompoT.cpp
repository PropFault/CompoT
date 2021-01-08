#include <iostream>
#include "Synapse.h"
#include "ComponentProvider.h"
#include "Component.h"
#include "System.h"
#include <string>
using namespace CompoT;

class CounterComponent : public Component{
private:
    int goal;
    int counter;
    int fakeLoad;
public:
    CounterComponent()
    :counter(0){
        goal = rand()%100000;
        fakeLoad = rand()%1000;
    }

    int getGoal()const{
        return this->goal;
    }

    int getCounter()const{
        return this->counter;
    }

    int getFakeLoad()const{
        return this->fakeLoad;
    }

    void setGoal(int goal){
        this->goal = goal;
    }

    void setCounter(int counter){
        this->counter = counter;
    }

    void setFakeLoad(int fakeLoad){
        this->fakeLoad = fakeLoad;
    }

    bool hasReachedGoal()const{
        return this->counter >= this->goal;
    }
};

class StringConcatComponent : public Component{
private:
    std::string storedString;
    std::string concatBit;
public:
    StringConcatComponent()
    :storedString("It goes "), concatBit("on and "){}

    const std::string &getStoredString()const{
        return this->storedString;
    }

    const std::string &getConcatBit()const{
        return this->concatBit;
    }

    void setStoredString(const std::string &storedString){
        this->storedString = storedString;
    }

    void setConcatBit(const std::string &concatBit){
        this->concatBit = concatBit;
    }
};

class MyComponentProvider : public ComponentProvider{
    private:
    std::vector<Component*> counters;
    std::vector<Component*> stringConcats;
    public:
    
    MyComponentProvider(){
        counters.push_back(new CounterComponent());
        counters.push_back(new CounterComponent());
        counters.push_back(new CounterComponent());
        counters.push_back(new CounterComponent());
        counters.push_back(new CounterComponent());
        counters.push_back(new CounterComponent());
        counters.push_back(new CounterComponent());
        counters.push_back(new CounterComponent());

        stringConcats.push_back(new StringConcatComponent());
        stringConcats.push_back(new StringConcatComponent());
        stringConcats.push_back(new StringConcatComponent());
        stringConcats.push_back(new StringConcatComponent());
        stringConcats.push_back(new StringConcatComponent());
        stringConcats.push_back(new StringConcatComponent());
        stringConcats.push_back(new StringConcatComponent());
        stringConcats.push_back(new StringConcatComponent());
    }

    virtual std::vector<Component*> getComponentsForType(const std::string &str)override{
        if(str == "counters")
            return this->counters;
        if(str == "stringCat")
            return this->stringConcats;
        throw std::runtime_error("BRUH");
    }
};

class CounterSystem : public System{
    public:
    CounterSystem():System("counters"){}
    virtual void run(const std::vector<Component*> &components)const override{
        srand(time(NULL));
        for(auto& component:components){
            auto counterComponent = component->get<CounterComponent>();
                    

            ///run logic
            for(int i = 0; i < counterComponent->getFakeLoad();i++){
                rand();
            }
            counterComponent->setCounter(counterComponent->getCounter()+1);

            if(counterComponent->hasReachedGoal() && (counterComponent->getCounter() %1000) == 0)
                std::cout<<"COUNTER REACHED GOAL(" << counterComponent->getCounter() << " >= " << counterComponent->getGoal() << std::endl;
        }
    }
};

class StringCatSystem : public System{
    public:
    StringCatSystem():System("stringCat"){}
    virtual void run(const std::vector<Component*> &components)const override{
        for(auto& component: components){
            auto stringCat = component->get<StringConcatComponent>();
            stringCat->setStoredString(stringCat->getStoredString() + stringCat->getConcatBit());
        }
    }
};

void say_hello(){
    std::cout << "Hello, from CompoT!\n";
}
bool started = true;
void fun(){
    srand(time(NULL));

    MyComponentProvider provider;
    Synapse synapse(provider);    
    synapse.add(new StringCatSystem());
    synapse.add(new CounterSystem());
    while(started){
        synapse.execute();
    }
}
int main(){
    std::thread t(fun);
    getchar();
    started = false;
    t.join();
    std::cout<<"end"<<std::endl;
    return 1;
}