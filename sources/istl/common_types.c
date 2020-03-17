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

static mcell_t *get_mcell(void *ptr)
{
    return (ptr - sizeof(mcell_t));
}

__attribute__((malloc))
void *snew(mdata_t m)
{
    mcell_t *mcell = malloc(sizeof(mcell_t) + m.data_size);

    *mcell = (mcell_t) {
        .dtor = m.destroy,
        .data = mcell + 1
    };
    *(int*)mcell->data = 4;
    return (mcell->data);
}

void sdel(void *data)
{
    mcell_t *mcell = get_mcell(data);

    if (data == NULL || (data != mcell->data))
        return;
    if (mcell->dtor != 0)
        mcell->dtor(mcell->data);
    free(mcell);
}
