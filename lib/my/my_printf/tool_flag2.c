/*
** EPITECH PROJECT, 2019
** tool_flag1
** File description:
** auxiliary func
*/

#include <stdarg.h>
#include <stdio.h>
#include "tool_cast.h"
#include "my.h"

void my_xflag(va_list *ap, const char *str, int i)
{
    long long x = va_arg(*ap, long long);

void (*cast_nb[])(long long *, char *, int) = {cast_char, cast_short,
        cast_long, cast_long_long, cast_long_long, cast_int, cast_int};

    if (is_lenmodify(str, i) != -84 && str && i)
        cast_nb[is_lenmodify(str, i)](&x, "0123456789abcdef", 16);
    else if (x < 0)
        my_put_uint((unsigned int)x, "0123456789abcdef", 16);
    else
        my_put_int((int)x, "0123456789abcdef", 16);
}

void my_xxflag(va_list *ap, const char *str, int i)
{
    long long x = va_arg(*ap, long long);
    void (*cast_nb[])(long long *, char *, int) = {cast_char, cast_short,
        cast_long, cast_long_long, cast_long_long, cast_int, cast_int};

    if (is_lenmodify(str, i) != -84 && str && i)
        cast_nb[is_lenmodify(str, i)](&x, "0123456789ABCDEF", 16);
    else if (x < 0)
        my_put_uint((unsigned int)x, "0123456789ABCDEF", 16);
    else
        my_put_int(x, "0123456789ABCDEF", 16);
}

void my_pflag(va_list *ap, const char *str, int i)
{
    void *p = va_arg(*ap, void *);

    if (str && i)
        my_put_address(p);
}

void my_percentflag(va_list *ap, const char *str, int i)
{
    if (str && i && ap)
        my_putchar('%');
}