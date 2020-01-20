/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** rtfm
*/

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include "tool_flag.h"
#include "my.h"

int is_lenmodify(const char *str, int i);

int is_flag(char const *src, int i);

void init_print(char const *src, int *i, va_list *ap);

int my_printf(const char *src, ...)
{
    int i = -1;
    va_list ap;

    va_start(ap, src);
    while (src[++i] != '\0') {
        if (src[i] == '%' && (is_flag(src, i + 1) != -84 ||
            is_lenmodify(src, i + 1) != -84))
            init_print(src, &i, &ap);
        else
            my_putchar(src[i]);
    }
    va_end(ap);
    return (0);
}