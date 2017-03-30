#ifndef TRANSFORM_H
#define TRANSFORM_H

#import "Watcher/watcher.hpp"

namespace VSL {
namespace Transform {
    // Fuzzy matches a AST subtree
    struct NodeTree {
        struct NodeMatch {
            NodeTree[] child;
            size_t children;
        }
        
        Parser::NodeType type;
        
        // Set to nullptr for no children
        NodeMatch children;
    }
    
    class Transformer {
        class WatcherTree {
        private:
            NodeTree* nodeTree;
        public: 
            WatcherTree( Watcher* watchers );
            
            // The associated watcher instance
            Watcher* watcher;
            
            // Checks if a node matches the AST transform
            inline bool matches( const Node& node );
        }
        
    private:
        WatcherTree[] watchers;
        Node* transform(Node*);
        
    public:
        Transformer();
        ~Transformer();
        
        // Set watchers
        void setWatchers(Watcher[] watcher, size_t size);
        
        // Functions to set watchers
        void defaultWatchers();
        
        // Set to root AST node to parse relative
        Node* root;
        
        // Applies transformations
        Node* transform(void);
    }
}
}

#endif TRANSFORM_H