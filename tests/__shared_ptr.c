/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#include "criterion/criterion.h"
#include "criterion/new/assert.h"
#include "istl/shared_ptr.h"

typedef struct TestingStructure {
    int a;
    int b;
} tstr_t;

void tstr_destroy(void *data)
{
    return;
}

const mdata_t MB_TEST = (mdata_t) {
    .copy = NULL,
    .destroy = tstr_destroy,
    .data_size = sizeof(tstr_t)
};

Test(unique_ptr, creation_and_destruction)
{
    tstr_t *sp = snew(MB_TEST);
    mcell_t *mcell = get_mcell(&sp);

    cr_assert(eq(ptr, mcell->data, sp, "Fatal error: wrong pointer allocation."));
    cr_expect(eq(ptr, mcell->dtor, MB_TEST.destroy));
    cr_expect(eq(int, mcell->type, SP_UNIQUE, "Wrong unique pointer type"));
    cr_expect(eq(ptr, mcell->count, NULL, "Wrong counter pointer. NULL expected."));
    cr_expect(eq(ptr, mcell->wcount, NULL, "Wrong weak counter pointer. NULL expected."));
    sdel(&sp);
}

Test(shared_ptr, creation_and_destruction)
{
    tstr_t *sp = shared_ptr(MB_TEST);
    mcell_t *mcell = get_mcell(&sp);

    cr_assert(eq(ptr, mcell->data, sp, "Fatal error: wrong pointer allocation."));
    cr_expect(eq(int, mcell->type, SP_SHARED, "Wrong unique pointer type"));
    cr_assert(ne(ptr, mcell->count, NULL, "Wrong counter pointer. Unexpected NULL."));
    cr_expect(eq(int, *mcell->count, 1));
    cr_assert(ne(ptr, mcell->wcount, NULL, "Wrong weak counter pointer. Unexpected NULL."));
    cr_expect(eq(int, *mcell->wcount, 0));
    cr_expect(eq(ptr, mcell->dtor, MB_TEST.destroy));
    sdel(&sp);
}

Test(shared_ptr, shared_ptr_copy)
{
    SMART tstr_t *sp1 = shared_ptr(MB_TEST);
    SMART tstr_t *sp2 = spcopy(sp1);
    mcell_t *mcell = get_mcell(&sp2);

    cr_assert(eq(ptr, mcell->data, sp1, "Fatal error: wrong pointer allocation."));
    cr_expect(eq(int, mcell->type, SP_SHARED, "Wrong unique pointer type"));
    cr_assert(ne(ptr, mcell->count, NULL, "Wrong counter pointer. Unexpected NULL."));
    cr_expect(eq(int, *mcell->count, 2));
    cr_assert(ne(ptr, mcell->wcount, NULL, "Wrong weak counter pointer. Unexpected NULL."));
    cr_expect(eq(int, *mcell->wcount, 0));
    cr_expect(eq(ptr, mcell->dtor, MB_TEST.destroy));
}
