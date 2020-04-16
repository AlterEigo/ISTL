/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/
#ifndef ISTL_ASTAR_H_INCLUDED
#define ISTL_ASTAR_H_INCLUDED

#include "istl/common_types.h"
#include "istl/list.h"

extern const mdata_t MB_PNODE;

typedef struct PathNode (pnode_t);

pnode_t *pnode_create(unsigned int, int score, bool_t);
void pnode_free(pnode_t **node_p);
void *pnode_copy(void const *node);
void pnode_destroy(void *node);
int pnode_link(pnode_t *lhs, pnode_t * rhs, int dist);
int pnode_detach(pnode_t *node);

#endif
