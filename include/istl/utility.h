/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/
#ifndef IS_UTILITY_H_INCLUDED
#define IS_UTILITY_H_INCLUDED

#include <SFML/Graphics.h>
#include "common_types.h"

#include <stdio.h>

typedef union UniType {
    int i_num;
    float f_num;
    char *str;
    void *ptr;
} utype_t;

extern const meta_bundle_t MB_UTYPE;

void utility_set_var(char const *, utype_t);
void *utility_get_var(char const *);
bool_t utility_sready(void);
void utility_reset(void);

/*!
    \brief Unsigned int value control
    \details Allows to determine if a value is between one bound
    and another, return this value if ```true``` or return
    bound value if not.
*/
uint_t expect_uint(uint_t val, uint_t lhs, uint_t rhs);

#endif
