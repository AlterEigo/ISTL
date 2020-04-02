/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#include <stdlib.h>
#include "istl/hash_table.h"

void ht_item_destroy(void *item)
{
    ht_item_t *tmp = (ht_item_t*)item;

    ht_item_free(&tmp);
}
