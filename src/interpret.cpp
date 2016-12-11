#include <iostream>
#include <sstream>
#include "run.hpp"

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

void NumberNode::run () {
}

