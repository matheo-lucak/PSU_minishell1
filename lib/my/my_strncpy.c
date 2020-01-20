/*
** EPITECH PROJECT, 2019
** my_strncpy
** File description:
** copies n characters from string to another
*/

int my_strlen(char const *string);

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    int len = my_strlen(src);

    while (i < n) {
        dest[i] = src[i];
        i++;
        if (i == n && len < n)
            dest[i] = '\0';
    }
    return (dest);
}
