/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/
#include <stdlib.h>
#include "istl/private/p_astar.h"

const mdata_t MB_PNODE = {
    .copy = pnode_copy,
    .destroy = pnode_destroy,
    .data_size = sizeof(pnode_t)
};

pnode_t *pnode_create(unsigned int id, int score, bool_t final)
{
    pnode_t *pnode = malloc(sizeof(pnode_t));

    pnode->id = id;
    pnode->score = score;
    pnode->goal = final;
    pnode->near = NULL;
    pnode->namount = 0;
    return (pnode);
}

void *pnode_copy(void const *node_p)
{
    pnode_t *nnode = NULL;
    pnode_t const *node = node_p;

    if (node == NULL)
        return (NULL);
    nnode = mem_copy(node, sizeof(pnode_t));
    if (node->near != NULL) {
        nnode->near = mem_copy(node->near, sizeof(bridge_t) * node->namount);
        nnode->namount = node->namount;
    }
    return (nnode);
}

void pnode_destroy(void *node_p)
{
    pnode_t *node = node_p;

    if (node == NULL)
        return;
    pnode_free(&node);
}

void pnode_free(pnode_t **node_p)
{
    pnode_t *node = NULL;

    if (node_p == NULL || (*node_p) == NULL)
        return;
    node = (*node_p);
    if (node->near != NULL)
        free(node->near);
    free(node);
    (*node_p) = NULL;
}

int pnode_advance(pnode_t *node, list_t *list)
{
    if (node == NULL || list == NULL)
        return (0);
    // Implement
    return (0);
}
