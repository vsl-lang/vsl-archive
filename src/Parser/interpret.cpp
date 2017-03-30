#include <iostream>
#include <sstream>
#include "run.hpp"

namespace VSL {
    namespace Parser {
        std::map<Operator, std::string> operator_names = {
            { Operator::NONE, "" },
            { Operator::RANGE, "Range" },
            { Operator::ASSIGN, "Assign" },
            { Operator::STRICT_ASSIGN, "Strict assign" },
            { Operator::LEFT_SHIFT_EQUALS, "Left shift equals" },
            { Operator::RIGHT_SHIFT_EQUALS, "Right shift equals" },
            { Operator::PLUS_EQUALS, "Plus equals" },
            { Operator::MINUS_EQUALS, "Minus equals" },
            { Operator::DIVIDE_EQUALS, "Divide equals" },
            { Operator::TIMES_EQUALS, "Times equals" },
            { Operator::MODULO_EQUALS, "Modulo equals" },
            { Operator::POWER_EQUALS, "Power equals" },
            { Operator::BITWISE_AND_EQUALS, "Bitwise and equals" },
            { Operator::BITWISE_OR_EQUALS, "Bitwise or equals" },
            { Operator::BITWISE_XOR_EQUALS, "Bitwise xor equals" },
            { Operator::IS, "Is" },
            { Operator::ISSUB, "Is subclass" },
            { Operator::EQUAL, "Equal" },
            { Operator::NOT_EQUAL, "Not equal" },
            { Operator::SPACESHIP, "Spaceship" },
            { Operator::LESS_THAN_OR_EQUAL, "Less than or equal" },
            { Operator::GREATER_THAN_OR_EQUAL, "Greater than or equal" },
            { Operator::LESS_THAN, "Less than" },
            { Operator::GREATER_THAN, "Greater than" },
            { Operator::LOGICAL_XOR, "Logical xor" },
            { Operator::LOGICAL_OR, "Logical or" },
            { Operator::LOGICAL_AND, "Logical and" },
            { Operator::LOGICAL_NOT, "Logical not" },
            { Operator::LEFT_SHIFT, "Left shift" },
            { Operator::RIGHT_SHIFT, "Right shift" },
            { Operator::PLUS, "Plus" },
            { Operator::MINUS, "Minus" },
            { Operator::DIVIDE, "Divide" },
            { Operator::TIMES, "Times" },
            { Operator::MODULO, "Modulo" },
            { Operator::POWER, "Power" },
            { Operator::BITWISE_AND, "Bitwise and" },
            { Operator::BITWISE_OR, "Bitwise or" },
            { Operator::BITWISE_XOR, "Bitwise xor" },
            { Operator::BITWISE_NOT, "Bitwise not" },
            { Operator::CAST, "Cast" },
            { Operator::MAP, "Map" },
            { Operator::CHAIN, "Chain" },
            { Operator::NEGATE, "Negate" },
            { Operator::POSITIVE, "Positive" }
        };
        
        std::map<NodeType, std::string> node_names = {
            { NodeType::BASE, "" },
            { NodeType::REGEX, "Regex" },
            { NodeType::SET, "Set" },
            { NodeType::TUPLE, "Tuple" },
            { NodeType::ARRAY, "Array" },
            { NodeType::DICTIONARY, "Dictionary" },
            { NodeType::STRING, "String" },
            { NodeType::NUMBER, "Number" },
            { NodeType::KEY_VALUE_PAIR, "Key-value pair" },
            { NodeType::KEY_VALUE_PAIRS, "Key-value pairs" },
            { NodeType::DATA, "" },
            { NodeType::CALL, "Call" },
            { NodeType::SUBSCRIPT, "Subscript" },
            { NodeType::VARIABLE_DECLARATION, "Variable declaration" },
            { NodeType::TYPED, "Typed" },
            { NodeType::PROPERTY_SUFFIX, "Property suffix" },
            { NodeType::PROPERTY, "Property" },
            { NodeType::DECLARATION, "Declaration" },
            { NodeType::TYPE, "Type" },
            { NodeType::INITIALIZER, "Initializer" },
            { NodeType::ARGUMENTS, "Arguments" },
            { NodeType::BINARY_EXPRESSION, "Binary expression" },
            { NodeType::UNARY_EXPRESSION, "Unary expression" },
            { NodeType::EXPRESSIONS, "Expressions" },
            { NodeType::COMMAND_CHAIN, "Command chain" },
            { NodeType::STATEMENT, "Statement" },
            { NodeType::FUNCTION, "Function" },
            { NodeType::PROGRAM, "Program" }
        };
        
        Node::Node(NodeType type) : children(std::vector<Node>()), type(type) {}
        Node::Node(std::string value, NodeType type) : data(value), type(type) {}
        Node::Node(std::vector<Node> nodes, NodeType type) : children(nodes), type(type) {}
        Node::Node(std::initializer_list<Node> nodes, NodeType type) : children(nodes), type(type) {}
        Node::Node(std::vector<Node> nodes, Operator operator_type, NodeType type) : children(nodes), type(type), operator_type(operator_type) {}
        Node::Node(std::initializer_list<Node> nodes, Operator operator_type, NodeType type) : children(nodes), type(type), operator_type(operator_type) {}
        
        std::string Node::run (std::string padding) {
            //TODO: transformers go here probably
            if (!node_names[this->type].size())
                return padding + "\"" + this->data + "\"\n";
            std::stringstream result;
            if (this->type == NodeType::BINARY_EXPRESSION || this->type == NodeType::UNARY_EXPRESSION)
                result << padding << operator_names[this->operator_type] << '\n';
            else
            result << padding << node_names[this->type] << '\n';
            int old_size = padding.size();
            if (old_size >= 3) {
                std::string last_chars = padding.substr(old_size - 3, 3);
                if (last_chars == "├")
                    padding = padding.substr(0, old_size - 3) + "│";
                else if (last_chars == "└")
                    padding = padding.substr(0, old_size - 3) + " ";
            }
            if (this->data.size())
                result << padding << "└\"" << this->data << "\"\n";
            else if (this->children.size()) {
                std::string new_padding = padding + "├";
                for (size_t i = 0; i < this->children.size() - 1; i++)
                    result << this->children[i].run(new_padding);
                new_padding = padding + "└";
                Node item = this->children[this->children.size() - 1];
                result << item.run(new_padding);
            }
            return result.str();
        }
        
        void Node::add (Node node) {
            this->children.push_back(node);
        }
    }
}
