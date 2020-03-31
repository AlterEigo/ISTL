/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/
#ifndef PRIVATE_OBSERVABLE_H_INCLUDED
#define PRIVATE_OBSERVABLE_H_INCLUDED

#include "istl/common_types.h"
#include "istl/list.h"
#include "istl/observable.h"

typedef struct Observable {
    list_t *subs;
    list_t *callbacks;
} (observable_t);

#endif
