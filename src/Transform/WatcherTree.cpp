#include "Transform.hpp"

namespace VSL {
namespace Transform {
    class Transformer::WatcherTree {
        WatcherTree(Watcher* watcher): watcher(watcher), nodeTree(watcher->nodeTree) {
        }
        
        bool matches(const Node* node, const NodeTree* matcher) {
            // We'll match a node on two conditions:
            //  1. It's type matches
            //  2. It's children fuzzy match the children types
            
            // Check the node type
            if (matcher->type != node->type) return false;
            
            // If they are any children fuzzy match using position
            if (matcher->children.children > 0) {
                bool result = false;
                
                // Stored fuzzy match position.
                // Should fullfill all children
                size_t position = 0;
                
                for (const Node& node : node->children) {
                    // Recurse on all children, they'll git git the base case
                    //  if no children
                    // It may or may not be helpful to check whether the children
                    //  would hit the base case and run that without the loop
                    //  however in that case, mearly the only cost saving would be
                    //  the call
                    if (matches(&node, &(matched->children.child[position]))) {
                        // Advance to the next matcher child
                        //  this in effect declared that the exisitng
                        //  child has been succesfully matched
                        position++;
                        
                        // If we have successfully matched
                        //  position (in essence the number of succesful matches)
                        //  will be equal to the child count
                        if (position >= matched->children.children)
                            break;
                    }
                }
                
                // If we could fuzzy match all of them, then we can start
                return position >= matched->children.children;
            } else {
                return true;
            }
        }
        
        bool matches(const Node* node) {
            return matches(node, nodeTree);
        }
    }
}
}