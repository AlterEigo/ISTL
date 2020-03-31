/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/
#include <stdlib.h>
#include "istl/private/p_observable.h"

int obs_subscribe(
        observable_t *obs,
        void *observer,
        obs_callback_ft cb)
{
    if (obs == NULL || observer == NULL || cb == NULL)
        return (-1);
    return (0);
}
