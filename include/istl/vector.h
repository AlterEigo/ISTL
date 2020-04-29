/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#ifndef ISTL_VECTOR_H_INCLUDED
#define ISTL_VECTOR_H_INCLUDED

typedef struct Vector (vector_t);

vector_t *vector_create(mdata_t type);
void vector_free(vector_t **vec);
void vector_destroy(void *);
void *vector_copy(void const *);

int vector_set(vector_t *, uint_t, void const *);

#endif
