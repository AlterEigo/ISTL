/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#include <stdlib.h>
#include "istl/private/p_vector.h"

vector_t *vector_push(vector_t *vec, void const *cdata)
{
    if (vec == NULL)
        return (NULL);
    if (vec->size == vec->capacity)
        vector_expand(vec);
    vec->size += 1;
    vector_set(vec, vec->size - 1, cdata);
    return (vec);
}

uint_t vector_expand(vector_t *vec)
{
    void **data = NULL;

    if (vec == NULL)
        return (0);
    vec->capacity *= 2;
    data = malloc(sizeof(void *) * vec->capacity);
    for (uint_t i = 0; i < vec->capacity; i++)
        data[i] = (i < vector_len(vec)) ? vec->data[i] : NULL;
    free(vec->data);
    vec->data = data;
    return (vec->capacity);
}

int vector_iswap(vector_t *vec, uint_t idx1, uint_t idx2)
{
    void *data = NULL;

    if (vec == NULL || NMAX(idx1, idx2) >= vector_len(vec))
        return (-1);
    data = vec->data[idx1];
    vec->data[idx1] = vec->data[idx2];
    vec->data[idx2] = data;
    return (0);
}
