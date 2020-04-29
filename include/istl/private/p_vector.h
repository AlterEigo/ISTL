/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#ifndef ISTL_VECTOR_PRIVATE_H_INCLUDED
#define ISTL_VECTOR_PRIVATE_H_INCLUDED

#include "istl/common_types.h"
#include "istl/utility.h"
#include "istl/vector.h"

extern const mdata_t MB_VECTOR;

typedef struct Vector {
    void **data;
    uint_t size;
    uint_t capacity;
} (vector_t);

vector_t *vector_create(mdata_t type);
void vector_free(vector_t **vec);
void vector_destroy(void *);
void *vector_copy(void const *);

int vector_set(vector_t *, uint_t, void const *);

#endif
