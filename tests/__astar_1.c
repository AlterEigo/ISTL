#include <criterion/criterion.h>

#include "istl/private/p_astar.h"

Test(pnode_advance, argument_checks)
{
    int res = pnode_advance(NULL, NULL);

    cr_expect(res == 0);
}

Test(pnode_advance, filling_argument_list)
{
    list_t *args = list_create(MB_PNODE);
    pnode_t *node = pnode_create(0, 5);
    pnode_t *ref = NULL;
    iterator_t it;

    pnode_link(node, node, 5);
    pnode_link(node, node, 4);
    pnode_link(node, node, 3);
    pnode_advance(node, args);

    cr_assert(list_len(args) == 3);
    it = list_begin(args);
    for (int i = 3; !list_final(args, it); it = it_next(it), i++) {
        ref = it_data(it);
        cr_assert(ref != NULL);
        cr_expect(
                ref->score == (5 + i),
                "Expected : '%d' Received : '%d'",
                (5 + i),
                ref->score);
    }
}
