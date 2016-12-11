#include "Scope.hpp"

using namespace vsl;

Variable& Scope::get(std::string key) {
    map<std::string, Variable*>::iterator iterator = this->data.find(key);
    if (iterator != this->data.end())
        return iterator->second;
    
    return NULL;
}

void Scope::set(std::string key, Variable& value) {
    this->data[key] = value;
}