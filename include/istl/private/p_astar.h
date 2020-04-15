/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/
#ifndef ISTL_ASTAR_PRIVATE_H_INCLUDED
#define ISTL_ASTAR_PRIVATE_H_INCLUDED

#include "istl/astar.h"

typedef struct Bridge {
    int score;
    pnode_t *epoint;
} (bridge_t);

typedef struct PathNode {
    unsigned int id;
    int score;
    bool_t goal;
    unsigned int namount;
    bridge_t *near;
} (pnode_t);

int pnode_advance(pnode_t *node, list_t *list);
pnode_t *pnode_create(unsigned int, int score, bool_t);
void pnode_free(pnode_t **node_p);
void *pnode_copy(void const *node);
void pnode_destroy(void *node);

#endif
