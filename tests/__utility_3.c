/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/
#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "istl/utility.h"

Test(regex_extract, simple_pattern_check)
{
    cr_expect(eq(int, regex_extract("", REGEX_UINT, NULL), FALSE));
    cr_expect(eq(int, regex_extract("45654", REGEX_UINT, NULL), TRUE));
    cr_expect(eq(int, regex_extract("-45", REGEX_UINT, NULL), TRUE));
    cr_expect(eq(int, regex_extract("0", REGEX_UINT, NULL), TRUE));
    cr_expect(eq(int, regex_extract("0.5", REGEX_UINT, NULL), FALSE));
    cr_expect(eq(int, regex_extract("542.801", REGEX_UINT, NULL), FALSE));
    cr_expect(eq(int, regex_extract("542.000", REGEX_UINT, NULL), TRUE));
    cr_expect(eq(int, regex_extract("-9143.00", REGEX_UINT, NULL), TRUE));
    cr_expect(eq(int, regex_extract("-914dqsd3.00", REGEX_UINT, NULL), FALSE));
    cr_expect(eq(int, regex_extract("asda624", REGEX_UINT, NULL), FALSE));
}
