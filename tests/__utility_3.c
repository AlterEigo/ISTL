/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/
#include <criterion/criterion.h>
#include "istl/string.h"
#include "istl/hash_table.h"
#include "istl/utility.h"

Test(regex_extract, pattern_validation_check)
{
    cr_expect(regex_extract("", REGEX_UINT, NULL) == FALSE);
    cr_expect(regex_extract("45654", REGEX_UINT, NULL) == TRUE);
    cr_expect(regex_extract("-45", REGEX_UINT, NULL) == TRUE);
    cr_expect(regex_extract("0", REGEX_UINT, NULL) == TRUE);
    cr_expect(regex_extract("0.5", REGEX_UINT, NULL) == FALSE);
    cr_expect(regex_extract("542.801", REGEX_UINT, NULL) == FALSE);
    cr_expect(regex_extract("542.000", REGEX_UINT, NULL) == TRUE);
    cr_expect(regex_extract("-9143.00", REGEX_UINT, NULL) == TRUE);
    cr_expect(regex_extract("-914dqsd3.00", REGEX_UINT, NULL) == FALSE);
    cr_expect(regex_extract("asda624", REGEX_UINT, NULL) == FALSE);
}

Test(regex_extract, null_arguments_crash_test)
{
    map_t *grp = map_create(5, MB_STR);

    regex_extract(NULL, NULL, NULL);
    regex_extract("", NULL, NULL);
    regex_extract(NULL, REGEX_UINT, NULL);
    regex_extract(NULL, NULL, grp);
    regex_extract("", REGEX_UINT, NULL);
    regex_extract("", NULL, grp);
    regex_extract("", REGEX_UINT, grp);
}
