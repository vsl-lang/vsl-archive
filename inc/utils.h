#pragma once

#include "ast.h"

#define ERROR_NULL(expr, block) if ((expr) == NULL) block
#define SAFE_MALLOC(var, size) if ((var = malloc(size)) == NULL) return NULL

/**
 * \brief Helper to make an ast_data_t
 * \param type The type
 * \param str String data
 * \param node AST node
 * \return Generated ast_data_t
 */
struct ast_data_t *make_ast_data(char type,
                                 char *str,
                                 struct ast_node_t *node);

/**
 * \brief Print an AST node
 * \param node The AST node
 * \param indent Indentation level (2*indent)
 */
void print_ast_node(struct ast_node_t *node, int indent);
