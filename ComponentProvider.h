#pragma once
#include <vector>
#include <string>
#include "Component.h"
namespace CompoT{
class ComponentProvider{
public:
    virtual std::vector<Component*> getComponentsForType(const std::string &str) = 0;
};
}