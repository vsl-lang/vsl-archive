#include "Transform.hpp"

#include <string>
#include <cmath>

#define ASTWatcher(name) VSL::Parser::Node* name(VSL::Parser::Node* node)

using namespace VSL;

/* Watchers */

// Folds numerical constants
ASTWatcher(ASTWatcherFoldNumericalConstants) {
    if (node->children[0].type == Parser::NodeType::NUMBER && node->children[1].type == Parser::NodeType::Number) {
        std::string lhs = node->children[0].data;
        std::string rhs = node->children[1].data;

        // Determine float or int.
        // Floats are a little more quirky than ints
        // so just to be safe lets not fold them now
        // Perhaps integrate compiler flag to modify this

        if (lhs.find('.') != std::string::npos && rhs.find('.') != std::string::npos) {
            // No `.` in essence means it's an integer
            // Now we can go ahead and convert to ints
            int lhs_i = atoi(lhs);
            int rhs_i = atoi(rhs);

            int res;

            switch (node->operator_type) {
                case Parser::Operator::PLUS  : res = lhs_i + rhs_i; break;
                case Parser::Operator::MINUS : res = lhs_i - rhs_i; break;
                case Parser::Operator::TIMES : res = lhs_i * rhs_i; break;
                case Parser::Operator::DIVIDE: res = lhs_i / rhs_i; break;
                case Parser::Operator::MODULO: res = lhs_i % rhs_i; break;

                default: return node;
            }
            
            Parser::Node* result(std::to_string(res), Parser::NodeType::NUMBER);
            return result;
        } else {
            return node;
        }
    } else {
        return node;
    }
}

namespace VSL {
namespace Transform {
    void Transformer::defaultWatchers() {
        Watcher[] watchers = {
            /* FoldNumericalConstants */ (Watcher){
                (NodeTree){ Parser::NodeType::BINARY_EXPRESSION, nullptr },
                &ASTWatcherFoldNumericalConstants
            }
        };
        setWatchers(watchers);
    }
}
}
