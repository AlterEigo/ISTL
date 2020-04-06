/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#include <criterion/criterion.h>
#include <criterion/new/assert.h>

#include <stdlib.h>
#include <time.h>

#include "istl/list.h"

void fill_int_list(list_t *list)
{
    int val;

    if (list == NULL)
        return;
    srand(time(NULL));
    for (int i = 0; i < 20; i++) {
        val = rand() % 1000;
        list_push_back(list, &val);
    }
}

bool_t sort_int_list(iterator_t lhs, iterator_t rhs)
{
    int *a = it_data(lhs);
    int *b = it_data(rhs);

    if (*a < *b) {
        return (TRUE);
    }
    return (FALSE);
}

void print_int_list(list_t *list)
{
    iterator_t it;
    int *ip = NULL;

    it = list_begin(list);
    for (; !list_final(list, it); it = it_next(it)) {
        ip = it_data(it);
        cr_log_warn("%d\n", *ip);
    }
}

Test(list_basic, create_destroy_list)
{

}

Test(list_sort, sort_integer_list)
{
    list_t *list = list_create(MB_INT);
    itr_t it;

    fill_int_list(list);
    list_sort(list, sort_int_list);
    it = it_next(list_begin(list));
    for (; !list_final(list, it); it = it_next(it)) {
        if (sort_int_list(it_back(it), it) == TRUE)
            cr_fatal("Wrong list's sorting operation.");
    }
}
