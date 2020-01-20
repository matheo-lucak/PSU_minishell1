/*
** EPITECH PROJECT, 2019
** my_strncat
** File description:
** concatenates n char of the src string to the dest
*/

#include <stdio.h>

int my_strlen(char const *string);

char *my_strncat(char *dest, char const *src, int n)
{
    int i = 0;
    int len_dest = my_strlen(dest);

    while (i < n && src[i] != '\0') {
        dest[len_dest + i] = src[i];
        i += 1;
    }
    dest[len_dest + i] = '\0';
    return (dest);
}
