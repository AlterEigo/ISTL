/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/
#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "istl/utility.h"

Test(str_uint, simple_pattern_check)
{
    cr_expect(eq(int, str_uint("45654"), TRUE));
    cr_expect(eq(int, str_uint("-45"), TRUE));
    cr_expect(eq(int, str_uint("0"), TRUE));
    cr_expect(eq(int, str_uint("0.5"), FALSE));
    cr_expect(eq(int, str_uint("542.801"), FALSE));
    cr_expect(eq(int, str_uint("542.000"), TRUE));
    cr_expect(eq(int, str_uint("-9143.00"), TRUE));
    cr_expect(eq(int, str_uint("-914dqsd3.00"), FALSE));
    cr_expect(eq(int, str_uint("asda624"), FALSE));
}
