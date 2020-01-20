/*
** EPITECH PROJECT, 2019
** tool_flag1
** File description:
** auxiliary func
*/

#include <stdarg.h>
#include <stdio.h>
#include "tool_flag.h"
#include "my.h"

void cast_char(long long *nb, char *base, int size)
{
    if ((int)*nb > 0 && (int)*nb <= 255 || size != 10)
        my_put_uchar((unsigned char)*nb, base, size);
    else
        my_put_char((char)*nb, base, size);
}

void cast_short(long long *nb, char *base, int size)
{
    if ((int)*nb > 0 && (int)*nb < 65535 || size != 10)
        my_put_ushort((unsigned short)*nb, base, size);
    else
        my_put_short((short)*nb, base, size);
}

void cast_int(long long *nb, char *base, int size)
{
    my_put_uint((unsigned int)*nb, base, size);
}

void cast_long(long long *nb, char *base, int size)
{
    my_put_long((long)*nb, base, size);
}

void cast_long_long(long long *nb, char *base, int size)
{
    my_put_long_long((long long)*nb, base, size);
}