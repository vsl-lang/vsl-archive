#pragma once

/// \brief AST data struct
struct ast_data_t {
    /**
     * \brief
     * AST data type
     * [0] String
     * [1] AST node
     */
    char type;
    /// \brief String or AST node
    union {
        /// \brief String value
        char *str;
        /// \brief AST node
        struct ast_node_t *node;
    };
};

/// \brief AST node
struct ast_node_t {
    /// \brief Type
    int type;
    /// \brief First argument
    struct ast_data_t *arg1;
    /// \brief Second argument
    struct ast_data_t *arg2;
};

enum ast_type {
    AST_PAIR,
    AST_CALL,
    // Literals
    AST_INTEGER,
    AST_FLOAT,
    AST_COMPLEX,
    AST_STRING,
    AST_CHAR,
    AST_NAME,
    // Operators
    AST_OP_ADD,
    AST_OP_SUB,
    AST_OP_MULT,
    AST_OP_DIV,
    AST_OP_MOD,
    AST_OP_POW,
    AST_OP_AND,
    AST_OP_OR,
    AST_OP_XOR,
    AST_OP_LSH,
    AST_OP_RSH,
    // Control structures
    AST_IF,
    AST_UNLESS,
    AST_WHILE,
    AST_UNTIL,
    // Other
    AST_MEMBER,
};

/**
 * \brief Create an AST node (need to be freed with destroy_ast_node)
 * \param type The type of the AST node
 * \param arg1 The first argument
 * \param arg2 The second argument
 * \return An AST node
 */
struct ast_node_t *make_ast_node(enum ast_type type,
                                 struct ast_data_t *arg1,
                                 struct ast_data_t *arg2);

/**
 * \brief Destroy an AST node
 * \param node The AST node
 */
void destroy_ast_node(struct ast_node_t *node);
