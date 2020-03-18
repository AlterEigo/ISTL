/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/
#include "istl/common_types.h"
#include <stdlib.h>

const meta_bundle_t MB_INT = {0, 0, sizeof(int)};
const meta_bundle_t MB_FLOAT = {0, 0, sizeof(float)};
const meta_bundle_t MB_DOUBLE = {0, 0, sizeof(double)};
const meta_bundle_t MB_CHAR = {0, 0, sizeof(char)};
const meta_bundle_t MB_PTR = {0, 0, sizeof(int*)};
const meta_bundle_t MB_BOOL = {0, 0, sizeof(bool_t)};

mcell_t *get_mcell(void *ptr)
{
    return (*(void**)ptr - sizeof(mcell_t));
}

__attribute__((malloc))
void *snew(mdata_t m)
{
    mcell_t *mcell = malloc(sizeof(mcell_t) + m.data_size);

    *mcell = (mcell_t) {
        .type = SP_UNIQUE,
        .count = NULL,
        .dtor = m.destroy,
        .data = mcell + 1
    };
    return (mcell->data);
}

__attribute__((always_inline))
inline void sdel_unique(mcell_t *mcell)
{
    if (mcell->dtor != 0)
        mcell->dtor(mcell->data);
    free(mcell);
}

__attribute__((always_inline))
inline void sdel_shared(mcell_t *mcell)
{
    if (*mcell->count <= 1) {
        free(mcell->count);
        sdel_unique(mcell);
    } else {
        *mcell->count -= 1;
        free(mcell);
    }
}

__attribute__((always_inline))
inline void sdel_weak(mcell_t *mcell)
{

}

void sdel(void *data)
{
    mcell_t *mcell = get_mcell(data);

    if (data == NULL || (*(void**)data != mcell->data))
        return;
    if (mcell->type == SP_UNIQUE)
        sdel_unique(mcell);
    if (mcell->type == SP_SHARED)
        sdel_shared(mcell);
    if (mcell->type == SP_WEAK)
        sdel_weak(mcell);
}
