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

void print_octal(char c)
{
    my_putchar('\\');
    if (c <= 31)
        my_putchar('0');
    if (c <= 7)
        my_putchar('0');
    my_put_int(c, "01234567", 8);
}

int my_putsstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < 32 || str[i] >= 127)
            print_octal(str[i]);
        else
            my_putchar(str[i]);
        i += 1;
    }
    return (0);
}

void my_bflag(va_list *ap, const char *str, int i)
{
    long long b = va_arg(*ap, long long);
    void (*cast_nb[])(long long *, char *, int) = {cast_char, cast_short,
        cast_long, cast_long_long, cast_long_long, cast_int, cast_int};

    if (is_lenmodify(str, i) != -84 && str && i)
        cast_nb[is_lenmodify(str, i)](&b, "01", 2);
    else
        my_put_long_long(b, "01", 2);
}

void my_ssflag(va_list *ap, const char *str, int i)
{
    char *s = va_arg(*ap, char *);

    if (str && i)
        my_putsstr(s);
}
