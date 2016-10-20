#include "lib/stlnames.h"
#include "abs-macros.h"

class VSLCallable {
    
};

class VSLObject {
    
};

class VSLNull {
    // name not yet agreed upon, temporary
}

stlfunc* get_stl_function(string name) {
    if (name != FUNCTION_NAMES.end()) {
        return *FUNCTION_NAMES[name]
    } else {
        return nullptr;
    }
}
