/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#include <stdlib.h>
#include "istl/private/p_list.h"
#include "istl/utility.h"

void list_revert(list_t *list)
{
    iterator_t it;
    list_t *nlist = 0;

    if (list == 0)
        return;
    it = list_begin(list);
    nlist = list_create(list->type_meta);
    for (it = list_begin(list); !list_final(list, it); it = it_next(it))
        list_push_front(nlist, list_data(it));
    while (list_len(list) != 0)
        list_pop_front(list);
    for (it = list_begin(nlist); !list_final(nlist, it); it = it_next(it))
        list_push_back(list, list_data(it));
}

void list_iswap(iterator_t *lhs, iterator_t *rhs)
{
    void *data = 0;

    if (lhs == 0 || rhs == 0)
        return;
    data = list_data(*lhs);
    lhs->data = list_data(*rhs);
    rhs->data = data;
}
