/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/
#ifndef OBSERVABLE_H_INCLUDED
#define OBSERVABLE_H_INCLUDED

typedef struct Observable (observable_t);
typedef int (*obs_callback_ft)(void *observer, void *obs, int);

observable_t *obs_create();
void obs_free(observable_t **);
int obs_subscribe(observable_t *, void *, obs_callback_ft);
int obs_notify(observable_t *, int);
int obs_unsubscribe(observable_t *, void *);

#endif
