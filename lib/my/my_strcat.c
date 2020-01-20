/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** concatenate two strings
*/
#include <stdio.h>
#include <stdlib.h>

int my_strlen(char const *string);

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int j = 0;
    char *new_str = malloc(sizeof(char) *
        (my_strlen(dest) + my_strlen (src) + 1));

    if (!new_str || !src || !dest)
        return (NULL);
    while (dest[i]) {
        new_str[i] = dest[i];
        i += 1;
    }
    while (src[j]) {
        new_str[i + j] = src[j];
        j += 1;
    }
    new_str[j + i] = '\0';
    return (new_str);
}