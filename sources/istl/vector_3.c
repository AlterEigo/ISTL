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
