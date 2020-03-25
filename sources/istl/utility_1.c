/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#include "istl/private/p_utility.h"
#include "istl/hash_table.h"
#include <stdlib.h>

const meta_bundle_t MB_UTYPE = (meta_bundle_t){0, 0, sizeof(utype_t)};

uint_t expect_uint(uint_t val, uint_t lhs, uint_t rhs)
{
    val = val < lhs ? lhs : val;
    val = val > rhs ? rhs : val;
    return (val);
}
