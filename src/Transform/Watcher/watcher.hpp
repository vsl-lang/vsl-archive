#ifndef WATCHER_H
#define WATCHER_H

#include "../Transform.hpp"

namespace VSL {
namespace Transform {
    struct Watcher {
        NodeTree* tree;
        Node* (*transform)(Node*);
    };
}
}

#endif
