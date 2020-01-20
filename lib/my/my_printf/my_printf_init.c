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

int my_put_percent(void);

int is_flag(char const *src, int i)
{
    int j = -1;
    char *flag_pattern = "cdiosSuxXbp%";

    while (flag_pattern[++j]) {
        if (src[i] == flag_pattern[j])
            return (j);
    }
    return (-84);
}

void init_print(char const *src, int *i, va_list *ap)
{
    void (*print_elem[])(va_list *, const char *, int) = {my_cflag, my_dflag,
        my_dflag, my_oflag, my_sflag, my_ssflag, my_uflag, my_xflag,
        my_xxflag, my_bflag, my_pflag, my_percentflag};

    *i += 1;
    while (is_flag(src, *i) == -84)
            *i += 1;
    print_elem[is_flag(src, *i)](ap, src, *i);
}