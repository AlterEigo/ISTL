/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#include <stdlib.h>

#include "istl/shared_ptr.h"
#include "istl/private/p_vector.h"

const mdata_t MB_VECTOR = (mdata_t) {
    .copy = vector_copy,
    .destroy = vector_destroy,
    .data_size = sizeof(vector_t)
};

vector_t *vector_create(mdata_t type)
{
    vector_t *vec = shared_ptr(MB_VECTOR);

    vec->size = 0;
    vec->capacity = 1;
    vec->tmeta = type;
    vec->data = malloc(sizeof(void *) * vec->capacity);
    return (vec);
}

void vector_free(vector_t **vec_p)
{
    if (vec_p == NULL || (*vec_p) == NULL)
        return;
    spdestroy(*vec_p);
    (*vec_p) = NULL;
}

void vector_destroy(void *vec_p)
{
    vector_t *vec = vec_p;

    if (vec == NULL)
        return;
    for (uint_t i = 0; i < vector_len(vec); i++)
        if (vec->tmeta.destroy == NULL)
            free(vec->data[i]);
        else
            vec->tmeta.destroy(vec->data[i]);
}

void *vector_copy(void const *vec_p)
{
    return (NULL);
}
