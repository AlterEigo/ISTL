/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#include "istl/private/p_utility.h"
#include "istl/hash_table.h"
#include <stdlib.h>

const meta_bundle_t MB_UTYPE = {0, 0, sizeof(utype_t)};
const fnode_t FNODE_NULL = {.cset = NULL, .ps = -1, .ns = -1, .fs = FALSE };
const char CSET_ALPHA[] = {
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
    'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
    'w', 'x', 'y', 'z',
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K',
    'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
    'W', 'X', 'Y', 'Z', '\0'
};
const fnode_t REGEX_UINT[] = {
    {.cset = "+-", .ps = 0, .ns = 1, .fs = FALSE, .gwl = 1, .gwr = 2},
    {.cset = "0123456789", .ps = 0, .ns = 2, .fs = TRUE, .gwl = 2, .gwr = 3},
    {.cset = "0123456789", .ps = 1, .ns = 2, .fs = TRUE, .gwl = 2, .gwr = 3},
    {.cset = "0123456789", .ps = 2, .ns = 2, .fs = TRUE, .gwl = 2, .gwr = 3},
    {.cset = ".", .ps = 2, .ns = 3, .fs = TRUE, .gwl = 3, .gwr = 3},
    {.cset = "0", .ps = 3, .ns = 3, .fs = TRUE, .gwl = 3, .gwr = 3},
    FNODE_NULL
};
const fnode_t REGEX_OPT[] = {
    {.cset = "-", .ps = 0, .ns = 1, .fs = FALSE, .gwl = 0, .gwr = 0},
    {.cset = "-", .ps = 1, .ns = 2, .fs = FALSE, .gwl = 0, .gwr = 0},
    {.cset = CSET_ALPHA, .ps = 1, .ns = 3, .fs = TRUE, .gwl = 1, .gwr = 2},
    {.cset = CSET_ALPHA, .ps = 2, .ns = 2, .fs = TRUE, .gwl = 2, .gwr = 3},
    FNODE_NULL
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

fnode_t const *regex_forward(char c, const fnode_t arr[], int *state_p)
{
    int nstate = -1;
    fnode_t const *node_p = NULL;

    if (state_p == NULL || arr == NULL)
        return (NULL);
    for (uint_t i = 0; !fnode_null(arr + i); i++) {
        if (arr[i].ps != *state_p)
            continue;
        if (str_contains(arr[i].cset, c)) {
            nstate = arr[i].ns;
            node_p = arr + i;
        }
    }
    *state_p = nstate;
    return (node_p);
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
