/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/
#include <stdlib.h>

#define SMART __attribute__((cleanup(free_var)))

__attribute__((always_inline))
inline void free_var(void *data)
{
    free(*(void**)data);
}

int main(int argc, char **argv)
{
    SMART int *pint = malloc(sizeof(int));

    return (0);
}
