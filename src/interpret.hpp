#ifndef ASTIFY_H
#define ASTIFY_H
#include <string>
#include <map>
#include <vector>
#include <initializer_list>
#include <gmpxx.h>
#include "operators.hpp"

class Node {
public:
    void run();
    void add(Node node);
    Node();
    Node(std::string value);
    Node(std::vector<Node> nodes);
    Node(std::initializer_list<Node> nodes);
};

class RegexNode : public Node {
public:
    void run();
    RegexNode(Node value);
};

class SetNode : public Node {
public:
    void run();
    SetNode();
    SetNode(std::vector<Node> nodes);
    SetNode(std::initializer_list<Node> nodes);
};

class TupleNode : public Node {
public:
    void run();
    void add(Node node);
    TupleNode();
    TupleNode(std::vector<Node> nodes);
    TupleNode(std::initializer_list<Node> nodes);
};

class ArrayNode : public Node {
public:
    void run();
    ArrayNode(Node value);
};

class StringNode : public Node {
public:
    void run();
    StringNode(Node value);
};

class NumberNode : public Node {
public:
    void run();
    NumberNode(Node value);
};

class DataNode : public Node {
public:
    void run();
    DataNode();
    DataNode(std::string value);
};

class CallNode : public Node {
public:
    void run();
    CallNode();
    CallNode(std::vector<Node> nodes);
    CallNode(std::initializer_list<Node> nodes);
};

class SubscriptNode : public Node {
public:
    void run();
    SubscriptNode();
    SubscriptNode(std::vector<Node> nodes);
    SubscriptNode(std::initializer_list<Node> nodes);
};

class DeclarationNode : public Node {
public:
    void run();
    DeclarationNode(Node modifier, Node assignment);
};

class TypedNode : public Node {
public:
    void run();
    TypedNode(Node name, Node type);
};

class PropertySuffixNode : public Node {
public:
    void run();
    void add(Node node);
    PropertySuffixNode();
    PropertySuffixNode(std::vector<Node> nodes);
    PropertySuffixNode(std::initializer_list<Node> nodes);
};

class PropertyNode : public Node {
public:
    void run();
    PropertyNode(Node prefix);
    PropertyNode(Node prefix, Node suffix);
};

class OperatorNode : public Node {
public:
    OperatorNode(Operator value);
};

class BinaryExpressionNode : public Node {
public:
    void run();
    BinaryExpressionNode(Operator op, Node left, Node right);
};

class UnaryExpressionNode : public Node {
public:
    void run();
    UnaryExpressionNode(Operator op, Node item);
};

class CommandChainNode : public Node {
public:
    void run();
    void add(Node node);
    CommandChainNode();
    CommandChainNode(std::vector<Node> nodes);
    CommandChainNode(std::initializer_list<Node> nodes);
};

class StatementNode : public Node {
public:
    void run();
    StatementNode();
    StatementNode(std::vector<Node> nodes);
    StatementNode(std::initializer_list<Node> nodes);
};

class ProgramNode : public Node {
public:
    void run();
    void add(Node node);
    ProgramNode();
    ProgramNode(std::vector<Node> nodes);
    ProgramNode(std::initializer_list<Node> nodes);
};
#endif

