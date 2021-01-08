#pragma once
#include "Component.h"
#include <vector>
namespace CompoT
{
    class System{
    private:
        std::string targetType;
    public:
        System(const std::string targetType):targetType(targetType){}
        virtual void run(const std::vector<Component*> &components)const = 0;
        const std::string &getTargetType() const{
            return this->targetType;
        }
        bool operator==(const System &othr)const{
            return this->getTargetType() == othr.getTargetType();
        }
        virtual ~System(){
            std::cout<<"Sisthem destroied"<<std::endl;
        }
    };
} // namespace name
