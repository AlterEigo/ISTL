/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/
#ifndef OBSERVABLE_H_INCLUDED
#define OBSERVABLE_H_INCLUDED

#include "istl/common_types.h"
#include "istl/list.h"

typedef struct Observable (observable_t);
typedef int (*obs_callback_ft)(void *observer, void *obs, int);

int obs_subscribe(observable_t *, void *, obs_callback_ft);
int obs_notify(observable_t *, void *, int);
int obs_unsubscribe(observable_t *, void *);

#endif
