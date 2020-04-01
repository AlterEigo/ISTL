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

typedef struct HashMap (map_t);

#define GR_START 0x01
#define GR_END 0x02

typedef union UniType {
    int i_num;
    float f_num;
    char *str;
    void *ptr;
} utype_t;

typedef struct FaNode {
    cchar_t cset;
    int ps;
    int ns;
    bool_t fs;
    char flags;
} fnode_t;

extern const meta_bundle_t MB_UTYPE;
extern const fnode_t REGEX_UINT[];

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
bool_t str_contains(cchar_t set, char c);
bool_t str_uint(cchar_t str);
bool_t fnode_null(fnode_t const *);
bool_t fnode_gstart(fnode_t const *);
bool_t fnode_gend(fnode_t const *);
fnode_t const *regex_forward(char, const fnode_t[], int *);
bool_t regex_extract(cchar_t str, fnode_t const *const pattern, map_t *grp);

#endif
