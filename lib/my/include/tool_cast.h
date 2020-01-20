/*
** EPITECH PROJECT, 2019
** tool_flag
** File description:
** header for print
*/

#ifndef TOOL_CAST_H_
#define TOOL_CAST_H_

#include <stdarg.h>

void cast_char(long long *nb, char *base, int size);

void cast_short(long long *nb, char *base, int size);

void cast_int(long long *nb, char *base, int size);

void cast_long(long long *nb, char *base, int size);

void cast_long_long(long long *nb, char *base, int size);

int is_lenmodify(const char *str, int i);

#endif
