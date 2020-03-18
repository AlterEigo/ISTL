/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/
#include "istl/unique_ptr.h"

uptr_t make_unique(void *data)
{
    uptr_t ptr = (uptr_t) {
        .data = data
    };

    return (ptr);
}
