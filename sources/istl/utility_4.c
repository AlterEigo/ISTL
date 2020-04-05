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

void regex_adjust_stack(
        fnode_t const * node_p,
        int groups[],
        int *glen,
        int *idx)
{
    if (fnode_gend(node_p)) {
        groups[(*glen) - 1] = 0;
        (*glen) -= 1;
    }
    if (fnode_gstart(node_p)) {
        (*glen) += 1;
        groups[(*glen) - 1] = (*idx);
        (*idx) += 1;
    }
}

void regex_extract_char(
        char chr,
        const int groups[],
        int glen,
        map_t *grp)
{
    string_t *str_p = NULL;
    string_t *tmp = NULL;

    for (int j = 0; j < glen; j++) {
        str_p = (grp == NULL) ? NULL : map_pull(grp, groups[j]);
        tmp = str_addch(str_p, chr);
        str_free(&str_p);
        map_insert(grp, groups[j], tmp);
    }
}
