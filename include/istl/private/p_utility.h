/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/
#ifndef UTILITY_PRIVATE_H_INCLUDED
#define UTILITY_PRIVATE_H_INCLUDED

#include "istl/utility.h"
#include "istl/hash_table.h"

map_t *global_manager(int sig);
void regex_adjust_stack(fnode_t const *, int[], int *, int *);
void regex_extract_char(char, const int[], int, map_t *);

#endif
