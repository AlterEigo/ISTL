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

const char GR_START = 0x01;
const char GR_END = 0x02;

bool_t fnode_null(fnode_t const *node)
{
    bool_t res = TRUE;

    if (node == NULL)
        return (FALSE);
    res = (node->cset != NULL) ? FALSE : res;
    res = (node->ps != -1) ? FALSE : res;
    res = (node->ns != -1) ? FALSE : res;
    res = (node->fs != FALSE) ? FALSE : res;
    res = (node->flags != 0) ? FALSE : res;
    return (res);
}

bool_t fnode_gstart(fnode_t const *node)
{
    char sflag = GR_START;

    if (node == NULL)
        return (FALSE);
    sflag &= node->flags;
    return (sflag);
}

bool_t fnode_gend(fnode_t const *node)
{
    char rflag = GR_END;

    if (node == NULL)
        return (FALSE);
    rflag &= node->flags;
    return (rflag);
}

bool_t regex_extract(cchar_t str, fnode_t const *const pattern, map_t *grp)
{
    int state = 0;
    fnode_t const *node_p = NULL;
    bool_t final = FALSE;
    string_t *str_p = NULL;
    list_t *list = list_create(MB_INT);
    int idx = 0;

    if (str == NULL || pattern == NULL)
        return (FALSE);
    for (uint_t i = 0; str[i] != 0; i++) {
        final = FALSE;
        node_p = regex_forward(str[i], pattern, &state);
        if (node_p != NULL) {
            str_p = (grp == NULL) ? NULL : map_get(grp, state);
            str_addch(str_p, str[i]);
            final = node_p->fs;
        }
    }
    return (final);
}
