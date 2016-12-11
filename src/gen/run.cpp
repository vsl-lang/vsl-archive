#include <iostream>
#include <sstream>
#include "run.hpp"

std::map<Operator, std::string> operator_names = {
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

std::string Node::Name = "";
std::string RegexNode::Name = "Regex";
std::string SetNode::Name = "Set";
std::string TupleNode::Name = "Tuple";
std::string ArrayNode::Name = "Array";
std::string StringNode::Name = "String";
std::string NumberNode::Name = "Number";
std::string DataNode::Name = "";
std::string CallNode::Name = "Call";
std::string SubscriptNode::Name = "Subscript";
std::string DeclarationNode::Name = "Declaration";
std::string TypedNode::Name = "Typed";
std::string PropertySuffixNode::Name = "Property suffix";
std::string PropertyNode::Name = "Property";
std::string OperatorNode::Name = " ";
std::string BinaryExpressionNode::Name = "Binary expression";
std::string UnaryExpressionNode::Name = "Unary expression";
std::string CommandChainNode::Name = "Command chain";
std::string StatementNode::Name = "Statement";
std::string ProgramNode::Name = "Program";

Node::Node() : children(std::vector<Node>()), name(&Node::Name) {}
Node::Node(std::string value) : data(value), children(std::vector<Node>()), name(&Node::Name) {}
Node::Node(std::vector<Node> nodes) : children(nodes), name(&Node::Name) {}
Node::Node(std::initializer_list<Node> nodes) : children(nodes), name(&Node::Name) {}
Node::Node(std::string* name) : children(std::vector<Node>()), name(name) {}
Node::Node(std::string value, std::string* name) : data(value), children(std::vector<Node>()), name(name) {}
Node::Node(std::vector<Node> nodes, std::string* name) : children(nodes), name(name) {}
Node::Node(std::initializer_list<Node> nodes, std::string* name) : children(nodes), name(name) {}

RegexNode::RegexNode(Node value) : Node(value.data, &RegexNode::Name) {}

SetNode::SetNode() : Node(&SetNode::Name) {}
SetNode::SetNode(std::vector<Node> nodes) : Node(nodes, &SetNode::Name) {}
SetNode::SetNode(std::initializer_list<Node> nodes) : Node(nodes, &SetNode::Name) {}

TupleNode::TupleNode() : Node(&TupleNode::Name) {}
TupleNode::TupleNode(std::vector<Node> nodes) : Node(nodes, &TupleNode::Name) {}
TupleNode::TupleNode(std::initializer_list<Node> nodes) : Node(nodes, &TupleNode::Name) {}

ArrayNode::ArrayNode(Node value) : Node(value.children, &ArrayNode::Name) {}

StringNode::StringNode(Node value) : Node(value.data, &StringNode::Name) {}

NumberNode::NumberNode(Node value) : Node(value.data, &NumberNode::Name) {}

DataNode::DataNode() : Node(&DataNode::Name) {}
DataNode::DataNode(std::string value) : Node(value, &DataNode::Name) {}

CallNode::CallNode() : Node(&CallNode::Name) {}
CallNode::CallNode(std::vector<Node> nodes) : Node(nodes, &CallNode::Name) {}
CallNode::CallNode(std::initializer_list<Node> nodes) : Node(nodes, &CallNode::Name) {}

SubscriptNode::SubscriptNode() : Node(&SubscriptNode::Name) {}
SubscriptNode::SubscriptNode(std::vector<Node> nodes) : Node(nodes, &SubscriptNode::Name) {}
SubscriptNode::SubscriptNode(std::initializer_list<Node> nodes) : Node(nodes, &SubscriptNode::Name) {}

DeclarationNode::DeclarationNode(Node modifier, Node assignment) : Node({ modifier, assignment }, &DeclarationNode::Name) {}

TypedNode::TypedNode(Node name, Node type) : Node({ name, type }, &TypedNode::Name) {}

PropertySuffixNode::PropertySuffixNode() : Node(&PropertySuffixNode::Name) {}
PropertySuffixNode::PropertySuffixNode(std::vector<Node> nodes) : Node(nodes, &PropertySuffixNode::Name) {}
PropertySuffixNode::PropertySuffixNode(std::initializer_list<Node> nodes) : Node(nodes, &PropertySuffixNode::Name) {}

PropertyNode::PropertyNode(Node prefix) : Node({ prefix }, &PropertyNode::Name) {}
PropertyNode::PropertyNode(Node prefix, Node suffix) : Node({ prefix, suffix }, &PropertyNode::Name) {}

OperatorNode::OperatorNode(Operator value) : Node(operator_names[value], &OperatorNode::Name) {}

BinaryExpressionNode::BinaryExpressionNode(Operator op, Node left, Node right) : Node({ OperatorNode(op), left, right }, &BinaryExpressionNode::Name) {}

UnaryExpressionNode::UnaryExpressionNode(Operator op, Node item) : Node({ OperatorNode(op), item }, &UnaryExpressionNode::Name) {}

CommandChainNode::CommandChainNode() : Node(&CommandChainNode::Name) {}
CommandChainNode::CommandChainNode(std::vector<Node> nodes) : Node(nodes, &CommandChainNode::Name) {}
CommandChainNode::CommandChainNode(std::initializer_list<Node> nodes) : Node(nodes, &CommandChainNode::Name) {}

StatementNode::StatementNode() : Node(std::vector<Node>(), &StatementNode::Name) {}
StatementNode::StatementNode(std::vector<Node> nodes) : Node(nodes, &StatementNode::Name) {}
StatementNode::StatementNode(std::initializer_list<Node> nodes) : Node(nodes, &StatementNode::Name) {}

ProgramNode::ProgramNode() : Node(std::vector<Node>(), &ProgramNode::Name) {}
ProgramNode::ProgramNode(std::vector<Node> nodes) : Node(nodes, &ProgramNode::Name) {}
ProgramNode::ProgramNode(std::initializer_list<Node> nodes) : Node(nodes, &ProgramNode::Name) {}

std::string Node::run (std::string padding) {
    if (!this->name->size())
        return padding + "\"" + this->data + "\"\n";
    else if (*this->name == " ")
        return padding + this->data + '\n';
    std::stringstream result;
    result << padding << *this->name << '\n';
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
        for (size_t i = 0; i < this->children.size() - 1; i++) {
            Node item = this->children[i];
            result << item.run(new_padding);
        }
        new_padding = padding + "└";
        Node item = this->children[this->children.size() - 1];
        result << item.run(new_padding);
    }
    return result.str();
}

void Node::add (Node node) {
    this->children.push_back(node);
}

