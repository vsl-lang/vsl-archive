#ifndef NODES_H
#define NODES_H
namespace VSL {
    namespace Parser {
        enum class NodeType {
            BASE,
            REGEX,
            SET,
            TUPLE,
            ARRAY,
            DICTIONARY,
            STRING,
            NUMBER,
            KEY_VALUE_PAIR,
            KEY_VALUE_PAIRS,
            DATA,
            CALL,
            SUBSCRIPT,
            VARIABLE_DECLARATION,
            TYPED,
            PROPERTY_SUFFIX,
            PROPERTY,
            DECLARATION,
            TYPE,
            INITIALIZER,
            ARGUMENTS,
            BINARY_EXPRESSION,
            UNARY_EXPRESSION,
            EXPRESSIONS,
            COMMAND_CHAIN,
            STATEMENT,
            FUNCTION,
            PROGRAM
        };
    }
}
#endif