#ifndef ASTIFY_H
#define ASTIFY_H
#include <string>
#include <map>
#include <vector>
#include <initializer_list>
#include "operators.hpp"
#include "nodes.hpp"

namespace VSL {
    namespace Parser {
        extern std::map<Operator, std::string> operator_names;
        extern std::map<NodeType, std::string> node_names;

        class Node {
        public:
            std::string data = "";
            std::vector<Node> children;
            NodeType type;
            Operator operator_type;
            void add(Node node);
            std::string run(std::string padding="");
            Node(NodeType type = NodeType::BASE);
            Node(std::string value, NodeType type=NodeType::BASE);
            Node(std::vector<Node> nodes, NodeType type=NodeType::BASE);
            Node(std::initializer_list<Node> nodes, NodeType type=NodeType::BASE);
            Node(std::vector<Node> nodes, Operator operator_type, NodeType type=NodeType::BINARY_EXPRESSION);
            Node(std::initializer_list<Node> nodes, Operator operator_type, NodeType type=NodeType::BINARY_EXPRESSION);
        };
    }
}
#endif
