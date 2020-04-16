#include <criterion/criterion.h>

#include "istl/private/p_astar.h"

uint_t get_unique()
{
    static uint_t i = 0;

    return (i++);
}

pnode_t *get_node_web(void)
{
    const uint_t WSIZE = 7;
    pnode_t **web = malloc(sizeof(pnode_t *) * WSIZE);

    web[0] = pnode_create(0, 3);
    web[1] = pnode_create(1, 2);
    web[2] = pnode_create(2, 6);
    web[3] = pnode_create(3, 2);
    web[4] = pnode_create(4, 4);
    web[5] = pnode_create(5, 0);
    web[6] = pnode_create(6, 2);

    pnode_set_final(web[5], TRUE);
    pnode_link(web[0], web[1], 4);
    pnode_link(web[0], web[6], 4);

    pnode_link(web[1], web[0], 4);
    pnode_link(web[1], web[3], 2);
    pnode_link(web[1], web[2], 3);

    pnode_link(web[2], web[1], 3);
    pnode_link(web[2], web[4], 7);

    pnode_link(web[3], web[1], 2);
    pnode_link(web[3], web[5], 2);

    pnode_link(web[4], web[2], 7);
    pnode_link(web[4], web[5], 4);
    pnode_link(web[4], web[6], 4);

    pnode_link(web[5], web[4], 4);
    pnode_link(web[5], web[3], 2);

    pnode_link(web[6], web[0], 4);
    pnode_link(web[6], web[4], 4);
    return (NULL);
}

Test(astar_navigate, find_shortest_path)
{
    list_t *nodes = NULL;
    pnode_t *web = get_node_web();
    uint_t eids[4] = {0, 1, 3, 5};
    iterator_t it;

    nodes = astar_navigate(web);
    cr_assert(nodes != NULL, "A* returned NULL.");
    cr_assert(list_len(nodes) != 0, "A* did not found any path");
    it = list_begin(nodes);
    for (int i = 0; !list_final(nodes, it); it = it_next(it), i++) {
        pnode_t *d = it_data(it);
        cr_assert(i != 4, "A* did not found the optimal path.");
        cr_expect(d->id == eids[i]);
    }
}
