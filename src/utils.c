#include <stdlib.h>
#include <stdio.h>
#include "utils.h"

struct ast_data_t *make_ast_data(char type,
                                 char *str,
                                 struct ast_node_t *node) {
    struct ast_data_t *data;
    SAFE_MALLOC(data, sizeof(struct ast_data_t));
    data->type = type;
    if (type == 0) data->str = str;
    else           data->node = node;
    return data;
}

void print_ast_node(struct ast_node_t *node, int indent) {
    printf("% *cAST %d {\n", indent*2, ' ', node->type);
    if (node->arg1 != NULL) {
        if (node->arg1->type == 0)
            printf("% *cSTR '%s'\n", (indent + 1)*2, ' ', node->arg1->str);
        else
            print_ast_node(node->arg1->node, indent + 1);
    }
    if (node->arg2 != NULL) {
        if (node->arg2->type == 0)
            printf("% *cSTR '%s'\n", (indent + 1)*2, ' ', node->arg2->str);
        else
            print_ast_node(node->arg2->node, indent + 1);
    }
    printf("% *c}\n", indent*2, ' ');
}
