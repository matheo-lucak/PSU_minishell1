/*
** EPITECH PROJECT, 2019
** str dup
** File description:
** str dup
*/

#include <stdlib.h>

char *my_strncpy(char *dest, char const *src, int n);

int my_strlen(char *src);

char *my_strndup(char const *src, int n)
{
    char *str = malloc(sizeof(char) * (n + 1));

    if (str == NULL)
        return (NULL);
    my_strncpy(str, src, n);
    str[n] = '\0';
    return (str);
}
