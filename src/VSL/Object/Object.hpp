#ifndef OBJECT_H
#define OBJECT_H
#include "../vsl.hpp"

namespace vsl {
template<class vsl::Class*>
class Object: public Class {
    public:
        vsl::Method* init;
}
}

#endif