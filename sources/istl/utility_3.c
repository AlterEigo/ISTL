/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#include "istl/private/p_utility.h"
#include "istl/hash_table.h"
#include "istl/string.h"
#include <stdlib.h>

bool_t fnode_null(fnode_t const *node)
{
    bool_t res = TRUE;

    if (node == NULL)
        return (FALSE);
    res = (node->cset != NULL) ? FALSE : res;
    res = (node->ps != -1) ? FALSE : res;
    res = (node->ns != -1) ? FALSE : res;
    res = (node->fs != FALSE) ? FALSE : res;
    return (res);
}

bool_t regex_extract(cchar_t str, fnode_t const *const pattern, map_t *grp)
{
    int state = 0;
    fnode_t const *node_p = NULL;
    bool_t final = FALSE;
    int idx = 1;

    if (str == NULL || pattern == NULL)
        return (FALSE);
    for (uint_t i = 0; str[i] != 0; i++) {
        final = FALSE;
        node_p = regex_forward(str[i], pattern, &state);
        if (node_p != NULL) {
            final = node_p->fs;
            regex_extract_char(str[i], node_p, grp);
        }
    }
    if (final != TRUE)
        map_drop(grp);
    return (final);
}
