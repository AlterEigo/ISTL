/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/
#include <stdlib.h>
#include "istl/private/p_astar.h"
#include "istl/shared_ptr.h"
#include "istl/weak_ptr.h"
#include "istl/hash_table.h"

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
    link.dest = make_weak(rhs);
    near[0] = link;
    for (uint_t i = 1; i < lhs->namount; i++)
        near[i] = lhs->near[i - 1];
    if (lhs->near != NULL)
        free(lhs->near);
    lhs->near = near;
    return (0);
}

int pnode_detach(pnode_t *node)
{
    pnode_t *lam = NULL;
    wptr_t *wp = NULL;

    if (node == NULL)
        return (-1);
    if (node->near == NULL)
        return (0);
    for (uint_t i = 0; i < node->namount; i++) {
        wp = node->near[i].dest;
        sdel(&wp);
    }
    free(node->near);
    return (0);
}

void pnode_backtrace(pnode_t *node, list_t *nodes)
{
    pnode_t *from = NULL;

    if (node == NULL)
        return;
    if (nodes != NULL) {
        list_push_front(nodes, node);
        from = wptr_lock(node->from);
        pnode_backtrace(from, nodes);
        sdel(&from);
    }
}

list_t *astar_navigate(pnode_t *startpoint)
{
    list_t *f = NULL;
    pnode_t *node = NULL;
    list_t *found = NULL;

    if (startpoint == NULL)
        return (NULL);
    f = list_create(MB_PNODE);
    if (pnode_advance(startpoint, f) < 1)
        return (NULL);
    while (list_len(f) != 0) {
        node = list_pull(f, list_begin(f));
        if (node->goal == TRUE) {
            found = list_create(MB_PNODE);
            pnode_backtrace(node, found);
            return (found);
        }
        pnode_advance(node, f);
        list_sort(f, pnode_further_then);
    }
    return (NULL);
}
