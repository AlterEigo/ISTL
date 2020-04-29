/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#include <stdlib.h>
#include <time.h>
#include <criterion/criterion.h>

#include "istl/common_types.h"
#include "istl/utility.h"
#include "istl/shared_ptr.h"
#include "istl/private/p_vector.h"

vector_t *create_full_vector(uint_t size)
{
    vector_t *vec = vector_create(MB_INT);

    srand(time(NULL));
    for (uint_t i = 0; i < size; i++)
        vector_push(vec, (int[]) {rand() % 100});
    return (vec);
}

Test(vector_essentials, essentials_vector_tests)
{
    vector_t *vec = vector_create(MB_INT);

    cr_assert(vec != NULL);
    cr_expect(vector_len(vec) == 0);
    vector_free(&vec);
    vec = create_full_vector(50);
    cr_assert(vec != NULL);
    cr_expect(vector_len(vec) == 50,
            "Expected : '%d', but got '%d'", 50, vector_len(vec));
    spdestroy(vec);
}

Test(vector_copy, vector_copy_test)
{
    vector_t *vec1 = create_full_vector(50);
    vector_t *vec2 = NULL;

    cr_assert(vec1 != NULL);
    vec2 = vector_copy(vec1);
    cr_assert(vec1 != vec2);
    cr_expect(vector_len(vec2) == vector_len(vec1));
    for (uint_t i = 0; i < 50; i++) {
        cr_assert(vector_get(vec1, i) != NULL);
        cr_assert(vector_get(vec2, i) != NULL);
        cr_expect(vector_get(vec1, i) != vector_get(vec2, i));
        cr_expect(*(int*)vector_get(vec1, i) == *(int*)vector_get(vec2, i));
    }
}

Test(vector_push, vector_push_back)
{
    vector_t *vec1 = create_full_vector(10);
    uint_t len;

    cr_assert(vec1 != NULL);
    vector_push(vec1, (int[]) {47});
    len = vector_len(vec1);
    cr_assert(vector_get(vec1, len - 1) != NULL);
    cr_expect(*(int*)vector_get(vec1, len - 1) == 47);
    vector_push(vec1, (int[]) {49});
    len = vector_len(vec1);
    cr_expect(*(int*)vector_get(vec1, len - 1) == 49);
    vector_push(vec1, (int[]) {51});
    len = vector_len(vec1);
    cr_expect(*(int*)vector_get(vec1, len - 1) == 51);
}

Test(vector_pop, vector_pop_back)
{
    vector_t *vec1 = create_full_vector(10);

    cr_assert(vec1 != NULL);
    cr_expect(vector_pop(vec1));
    cr_expect(vector_len(vec1) == 9);
    cr_expect(vector_pop(vec1));
    cr_expect(vector_len(vec1) == 8);
    cr_expect(vector_pop(vec1));
    cr_expect(vector_len(vec1) == 7);
}

Test(vector_iswap, vector_item_swap)
{
    vector_t *vec1 = create_full_vector(10);
    const int val1 = 68924;
    const int val2 = 3455605;

    cr_assert(vec1 != NULL);
    vector_set(vec1, 1, &val1);
    vector_set(vec1, 8, &val2);
    cr_assert(vector_cget(vec1, 1) != NULL);
    cr_assert(vector_cget(vec1, 8) != NULL);
    vector_iswap(vec1, 1, 8);
    cr_assert(vector_cget(vec1, 1) != NULL);
    cr_assert(vector_cget(vec1, 8) != NULL);
    cr_expect(*(int *)vector_cget(vec1, 1) == val2);
    cr_expect(*(int *)vector_cget(vec1, 8) == val1);
}
