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
const fnode_t REGEX_UINT[] = {
        {.cset = "+-", .ps = 0, .ns = 1, .fs = FALSE},
        {.cset = "0123456789", .ps = 0, .ns = 2, .fs = FALSE},
        {.cset = "0123456789", .ps = 1, .ns = 2, .fs = TRUE},
        {.cset = "0123456789", .ps = 2, .ns = 2, .fs = TRUE},
        {.cset = ".", .ps = 2, .ns = 3, .fs = TRUE},
        {.cset = "0", .ps = 3, .ns = 3, .fs = TRUE},
        {0, 0, 0, 0}
};

uint_t expect_uint(uint_t val, uint_t lhs, uint_t rhs)
{
    val = val < lhs ? lhs : val;
    val = val > rhs ? rhs : val;
    return (val);
}

bool_t str_contains(cchar_t set, char c)
{
    if (set == NULL)
        return (FALSE);
    for (uint_t i = 0; set[i] != 0; i++) {
        if (set[i] == c)
            return (TRUE);
    }
    return (FALSE);
}

void regex_forward(char c, const fnode_t arr[], int *state_p)
{
    int nstate = -1;

    if (state_p == NULL || arr == NULL)
        return;
    for (uint_t i = 0; arr[i].cset != NULL; i++) {
        if (arr[i].ps != *state_p)
            continue;
        nstate = str_contains(arr[i].cset, c) ? arr[i].ns : nstate;
    }
    *state_p = nstate;
}

bool_t str_uint(cchar_t str)
{
    int state = 0;
    fnode_t const *const pattern = REGEX_UINT;

    if (str == NULL)
        return (FALSE);
    for (uint_t i = 0; str[i] != 0; i++) {
        regex_forward(str[i], pattern, &state);
    }
    return ((state > 1 && state < 4) ? TRUE : FALSE);
}
