/*
** EPITECH PROJECT, 2019
** my_memset
** File description:
** rtfm
*/

#include <stdlib.h>

void my_memset(char *str, char c, int len)
{
    int i = 0;

    if (!str)
        return ;
    while (i < len && str[i])
        str[i++] = c;
}
