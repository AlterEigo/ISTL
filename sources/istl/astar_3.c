/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/
#include <stdlib.h>
#include <stdio.h>
#include "istl/private/p_astar.h"

bool_t pnode_further_then(iterator_t lhs_it, iterator_t rhs_it)
{
    pnode_t *lhs = it_data(lhs_it);
    pnode_t *rhs = it_data(rhs_it);

    if (lhs->score > rhs->score)
        return (TRUE);
    return (FALSE);
}

void pnode_print(void *node_p)
{
    pnode_t *node = node_p;

    if (node == NULL)
        return;
}
