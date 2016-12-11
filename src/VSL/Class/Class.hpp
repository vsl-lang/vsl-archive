#ifndef CLASS_H
#define CLASS_H
#include "../vsl.hpp"

namespace vsl {
class Class: public Scope {
    public:
        static string name;

        Scope* scope;
}
}

#endif