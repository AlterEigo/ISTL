/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#include <stdlib.h>
#include "istl/shared_ptr.h"

void *shared_ptr(mdata_t tmeta)
{
    void *alloc = snew(tmeta);
    mcell_t *mcell = get_mcell(&alloc);

    mcell->type = SP_SHARED;
    mcell->count = malloc(sizeof(uint_t));
    *mcell->count = 1;
    return (mcell->data);
}

void *spcopy(void *ptr)
{
    mcell_t *mcell = get_mcell(&ptr);
    mcell_t *ncell = NULL;

    if (mcell->data != ptr)
        return (NULL);
    ncell = mem_copy(mcell, sizeof(mcell_t));
    *ncell->count += 1;
    return (ncell->data);
}
