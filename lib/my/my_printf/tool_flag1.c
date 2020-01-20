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

void my_cflag(va_list *ap, const char *str, int i)
{
    char c = va_arg(*ap, int);

    if (str && i)
        my_putchar(c);
}

void my_dflag(va_list *ap, const char *str, int i)
{
    long long d = va_arg(*ap, long long);
    void (*cast_nb[])(long long *, char *, int) = {cast_char, cast_short,
        cast_long, cast_long_long, cast_long_long, cast_int, cast_int};

    if (is_lenmodify(str, i) != -84 && str && i)
        cast_nb[is_lenmodify(str, i)](&d, "0123456789", 10);
    else
        my_put_int((int)d, "0123456789", 10);
}

void my_oflag(va_list *ap, const char *str, int i)
{
    long long o = va_arg(*ap, long long);
    void (*cast_nb[])(long long *, char *, int) = {cast_char, cast_short,
        cast_long, cast_long_long, cast_long_long, cast_int, cast_int};

    if (is_lenmodify(str, i) != -84 && str && i)
        cast_nb[is_lenmodify(str, i)](&o, "01234567", 8);
    else
        my_put_ulong((unsigned long)o, "01234567", 8);
}

void my_sflag(va_list *ap, const char *str, int i)
{
    char *s = va_arg(*ap, char *);

    if (str && i)
        my_putstr(s);
}

void my_uflag(va_list *ap, const char *str, int i)
{
    long long u = va_arg(*ap, long long);
    void (*cast_nb[])(long long *, char *, int) = {cast_char, cast_short,
        cast_long, cast_long_long, cast_long_long, cast_int, cast_int};
    if (is_lenmodify(str, i) != -84 && str && i)
        cast_nb[is_lenmodify(str, i)](&u, "0123456789", 10);
    else
        my_put_uint((unsigned int)u, "0123456789", 10);

}