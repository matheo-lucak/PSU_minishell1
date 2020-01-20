/*
** EPITECH PROJECT, 2019
** my_strstr
** File description:
** rtfm
*/

#include <unistd.h>
#include <stdio.h>

int my_strlen(char const *string);

int is_same_str(char *str, char *to_find, int *i, int len)
{
    int j = 0;

    while (str[*i] == to_find[j] && str[*i] != '\0' && str[j] != '\0') {
        *i += 1;
        j += 1;
        if (j == len) {
            *i -= j;
            return (1);
        }
    }
    return (0);
}

char *my_strstr(char *str, char *to_find)
{
    int i = 0;
    int is_same = 0;
    int sub_len = my_strlen(to_find);
    int str_len = my_strlen(str);

    while (i < str_len) {
        i += 1;
        is_same = is_same_str(str, to_find, &i, sub_len);
        if (is_same == 1) {
            return (&str[i]);
        }
    }
    return (0);
}
