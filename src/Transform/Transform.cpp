#include "Transform.hpp"

namespace VSL {
namespace Transform {
    
    Transformer::setWatchers(Watcher[] watcher, size_t size) {
        size_t length = size / sizeof(Watcher);
        
        watchers = new WatcherTree[length];
        
        for (size_t i = 0; i < length; i++) {
            watchers[i] = new WatcherTree(watchers[i]);
        }
    }
    
    Transformer::defaultWatchers() {
        
    }
    
    Transformer::~Transformer() {
        // Deintitalize watcher trees
        size_t length = sizeof(this->watchers) / sizeof(Watcher);
        for (size_t i = 0; i < length; i++)
            delete watchers[i];

        delete[] watchers;
    }
    
    Node* Transformer::transform(Node* node) {
        Watcher* watcher = nullptr;
        
        // First, find a matching watcher
        for (WatcherTree const& matcher : this->watchers) {
            // Check if
            if (matcher.matches(node)) {
                // Found our match, keep this watcher
                watcher = matcher.watcher;
                break;
            }
        }
        
        // Okay, well if there is a token then
        if (watcher != nullptr) {
            // Run the transformer and set it to node
            *node = (*(watcher->transform))(node);
        }
        
        // Determine if node is a parent, if so,
        // qualify the children for transformation
        for (Node const& children: node->children) {
            // TODO: multithread transformations
            // add a quality(Node*) queue which will
            // distribute operations
            this->transform(&children);
        }
        
        return node;
    }
    
    Node* Transformer::transform(void) {
        this->transform(this->root)
    }
}
}