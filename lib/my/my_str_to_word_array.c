/*
** EPITECH PROJECT, 2019
** my_str_to_word_array
** File description:
** splits a string into word
*/

#include <stdlib.h>
#include <stdio.h>

char *my_strndup(char const *src, int n);

int is_sep(char c, char *sep)
{
    int i = 0;

    while (sep[i]) {
        if (sep[i] == c)
            return (1);
        i++;
    }
    return (0);
}

int get_word_len(char const *str, char *sep)
{
    int len = 0;

    if (str == NULL)
        return (0);
    while (!is_sep(str[len], sep) && str[len] != '\0')
        len++;
    return (len);
}

int get_sep_len(char const *str, char *sep)
{
    int len = 0;

    if (str == NULL)
        return (0);
    while (is_sep(str[len], sep) && str[len] != '\0')
        len++;
    return (len);
}

int get_word_nbr(char const *str, char *sep)
{
    int i = get_word_len(str + get_sep_len(str, sep), sep);
    int j = get_sep_len(str + i, sep);

    if (i == 0)
        return (0);
    return (1 + get_word_nbr(str + i + j, sep));
}

char **my_str_to_word_array(char const *str, char *sep)
{
    char **arr = NULL;
    int i = 0;
    int word_counter = 0;

    arr = malloc(sizeof(char *) * (get_word_nbr(str, sep) + 1));
    if (!arr || !str || !sep)
        return (NULL);
    i += get_sep_len(str + i, sep);
    while (str[i]) {
        arr[word_counter] = my_strndup(str + i, get_word_len(str + i, sep));
        i += get_word_len(str + i, sep);
        i += get_sep_len(str + i, sep);
        word_counter++;
    }
    arr[word_counter] = NULL;
    return (arr);
}