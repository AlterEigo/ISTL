/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/
#ifndef PRIVATE_OBSERVABLE_H_INCLUDED
#define PRIVATE_OBSERVABLE_H_INCLUDED

#include "istl/observable.h"

typedef struct Observable {
    list_t *subs;
} (observable_t);

#endif
