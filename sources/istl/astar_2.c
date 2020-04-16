/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/
#include <stdlib.h>
#include "istl/private/p_astar.h"

int pnode_set_final(pnode_t *node, bool_t val)
{
    if (node == NULL)
        return (-1);
    node->goal = val;
    return (0);
}

int pnode_link(pnode_t *lhs, pnode_t * rhs, int dist)
{
    bridge_t link;
    bridge_t *near = NULL;

    if (lhs == NULL || rhs == NULL)
        return (-1);
    lhs->namount += 1;
    near = malloc(sizeof(bridge_t) * lhs->namount);
    link.score = dist;
    link.epoint = rhs;
    near[0] = link;
    for (uint_t i = 1; i < lhs->namount; i++)
        near[i] = lhs->near[i - 1];
    pnode_detach(lhs);
    lhs->near = near;
    return (0);
}

int pnode_detach(pnode_t *node)
{
    if (node == NULL)
        return (-1);
    if (node->near != NULL)
        free(node->near);
    return (0);
}

pnode_t *pnode_backtrace(pnode_t *node, list_t *nodes)
{
    if (node == NULL)
        return (NULL);
    if (nodes != NULL) {
        list_push_back(nodes, node);
        pnode_backtrace(node->from, nodes);
    }
    return (node->from);
}

list_t *astar_navigate(pnode_t *startpoint)
{
    list_t *f = NULL;
    list_t *s = NULL;
    iterator_t it;
    pnode_t *node = NULL;

    if (startpoint == NULL)
        return (NULL);
    if (pnode_advance(startpoint, f) == 0)
        return (NULL);
    f = list_create(MB_PNODE);
    s = list_create(MB_PNODE);
    it = list_begin(f);
    for (; !list_final(f, it); it = it_next(it)) {
        node = it_data(it);
    }
    return (NULL);
}
