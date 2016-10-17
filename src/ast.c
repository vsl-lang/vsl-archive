#include <stdlib.h>
#include <stdio.h>
#include "utils.h"
#include "ast.h"

struct ast_node_t *make_ast_node(enum ast_type type,
                                 struct ast_data_t *arg1,
                                 struct ast_data_t *arg2) {
    struct ast_node_t *node;
    SAFE_MALLOC(node, sizeof(struct ast_node_t));
    node->type = type;
    node->arg1 = arg1;
    node->arg2 = arg2;
    return node;
}

void destroy_ast_node(struct ast_node_t *node) {
    if (node->arg1 != NULL) {
        if (node->arg1->type == 0) free(node->arg1->str);
        else           destroy_ast_node(node->arg1->node);
        free(node->arg1);
    }
    if (node->arg2 != NULL) {
        if (node->arg2->type == 0) free(node->arg2->str);
        else           destroy_ast_node(node->arg2->node);
        free(node->arg2);
    }
}
