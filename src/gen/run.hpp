#ifndef ASTIFY_H
#define ASTIFY_H
#include <string>
#include <map>
#include <vector>
#include <initializer_list>
#include "operators.hpp"

extern std::map<Operator, std::string> operator_names;

class Node {
public:
    std::string data = "";
    std::vector<Node> children;
    std::string* name;
    static std::string Name;
    void add(Node node);
    std::string run(std::string padding="");
    Node();
    Node(std::string value);
    Node(std::vector<Node> nodes);
    Node(std::initializer_list<Node> nodes);
    Node(std::string* name);
    Node(std::string value, std::string* name);
    Node(std::vector<Node> nodes, std::string* name);
    Node(std::initializer_list<Node> nodes, std::string* name);
};

class RegexNode : public Node {
public:
    static std::string Name;
    RegexNode(Node value);
};

class SetNode : public Node {
public:
    static std::string Name;
    SetNode();
    SetNode(std::vector<Node> nodes);
    SetNode(std::initializer_list<Node> nodes);
};

class TupleNode : public Node {
public:
    static std::string Name;
    TupleNode();
    TupleNode(std::vector<Node> nodes);
    TupleNode(std::initializer_list<Node> nodes);
};

class ArrayNode : public Node {
public:
    static std::string Name;
    ArrayNode(Node value);
};

class StringNode : public Node {
public:
    static std::string Name;
    StringNode(Node value);
};

class NumberNode : public Node {
public:
    static std::string Name;
    NumberNode(Node value);
};

class DataNode : public Node {
public:
    static std::string Name;
    DataNode();
    DataNode(std::string value);
};

class CallNode : public Node {
public:
    static std::string Name;
    CallNode();
    CallNode(std::vector<Node> nodes);
    CallNode(std::initializer_list<Node> nodes);
};

class SubscriptNode : public Node {
public:
    static std::string Name;
    SubscriptNode();
    SubscriptNode(std::vector<Node> nodes);
    SubscriptNode(std::initializer_list<Node> nodes);
};

class DeclarationNode : public Node {
public:
    static std::string Name;
    DeclarationNode(Node modifier, Node assignment);
};

class TypedNode : public Node {
public:
    static std::string Name;
    TypedNode(Node name, Node type);
};

class PropertySuffixNode : public Node {
public:
    static std::string Name;
    PropertySuffixNode();
    PropertySuffixNode(std::vector<Node> nodes);
    PropertySuffixNode(std::initializer_list<Node> nodes);
};

class PropertyNode : public Node {
public:
    static std::string Name;
    PropertyNode(Node prefix);
    PropertyNode(Node prefix, Node suffix);
};

class OperatorNode : public Node {
public:
    static std::string Name;
    OperatorNode(Operator value);
};

class BinaryExpressionNode : public Node {
public:
    static std::string Name;
    BinaryExpressionNode(Operator op, Node left, Node right);
};

class UnaryExpressionNode : public Node {
public:
    static std::string Name;
    UnaryExpressionNode(Operator op, Node item);
};

class CommandChainNode : public Node {
public:
    static std::string Name;
    CommandChainNode();
    CommandChainNode(std::vector<Node> nodes);
    CommandChainNode(std::initializer_list<Node> nodes);
};

class StatementNode : public Node {
public:
    static std::string Name;
    StatementNode();
    StatementNode(std::vector<Node> nodes);
    StatementNode(std::initializer_list<Node> nodes);
};

class ProgramNode : public Node {
public:
    static std::string Name;
    std::string run(std::string padding="");
    ProgramNode();
    ProgramNode(std::vector<Node> nodes);
    ProgramNode(std::initializer_list<Node> nodes);
};
#endif

