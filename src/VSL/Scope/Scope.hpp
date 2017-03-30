#ifndef SCOPE_H
#define SCOPE_H

#include "vsl.hpp"

namespace vsl {
class Scope {
private:
    std::unordered_map<std::string, Variable*> data;
    
public:
    Variable& get(std::string key);
    void set(std::string key, Variable* value);
}
}

#endif