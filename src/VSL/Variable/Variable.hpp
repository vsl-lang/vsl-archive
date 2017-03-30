#ifndef VARIABLE_H
#define VARIABLE_H

#include "vsl.hpp"

namespace vsl {
class Variable {
public:
    Scope* value;
    Variable::AccessModifier access;
    
    Scope* resolve(void);
    
    Method* getter;
    Method* setter;
        
    static enum class AccessModifier {
        PUBLIC,
        PRIVATE,
        READONLY
    }
}
}

#endif