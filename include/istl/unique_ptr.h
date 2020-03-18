/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/
#ifndef ISTL_UNIQUE_PTR_INCLUDED
#define ISTL_UNIQUE_PTR_INCLUDED

#include "common_types.h"

typedef struct UniquePtr {
    void *data;
} (uptr_t);

uptr_t make_unique(void *);

#endif
