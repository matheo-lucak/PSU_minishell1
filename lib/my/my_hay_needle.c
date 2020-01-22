/*
** EPITECH PROJECT, 2019
** my_strcmp
** File description:
** compares the fst difference between two strings by returning the difference
*/

int my_strlen(char const *str);

int my_strncmp(char const *s1, char const *s2, int n);

int my_hay_needle(char *str, char *to_find)
{
    int i = 0;

    if (!str || !to_find)
        return (0);
    while (str[i]) {
        if (!my_strncmp(str + i, to_find, my_strlen(to_find)))
            return (i);
        i += 1;
    }
    return (0);
}