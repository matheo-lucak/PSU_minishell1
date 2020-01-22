/*
** EPITECH PROJECT, 2019
** str dup
** File description:
** str dup
*/

#include <stdlib.h>

char *my_strcpy(char *dest, char const *src);

int my_strlen(char *src);

char *my_strdup(char *src)
{
    char *str = NULL;

    if (!src)
        return (NULL);
    str = malloc(sizeof(char) * (my_strlen(src) + 1));
    if (!str)
        return (NULL);
    my_strcpy(str, src);
    return (str);
}
