/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#include "istl/private/p_vector.h"

const mdata_t MB_VECTOR = (mdata_t) {
    .copy = vector_copy,
    .destroy = vector_destroy,
    .data_size = sizeof(vector_t)
};

vector_t *vector_create(mdata_t type)
{
    return (NULL);
}

void vector_free(vector_t **vec_p)
{

}

void vector_destroy(void *vec_p)
{

}

void *vector_copy(void const *vec_p)
{
    return (NULL);
}
