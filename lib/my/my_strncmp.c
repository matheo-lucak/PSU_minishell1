/*
** EPITECH PROJECT, 2019
** my_strcmp
** File description:
** compares the fst difference between two strings by returning the difference
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    while (i < n && (s1[i] && s2[i])) {
        if (s1[i] > s2[i])
            return (1);
        if (s1[i] < s2[i])
            return (-1);
        i += 1;
    }
    return (0);
}
