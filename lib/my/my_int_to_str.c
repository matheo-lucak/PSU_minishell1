/*
** EPITECH PROJECT, 2019
** my_int_to_str
** File description:
** displays the number given as parameter
*/

#include <stdlib.h>

char *my_int_to_str(int nb)
{
    int i = 0;
    int tmp = nb;
    char *str;

    while (nb > 0) {
        nb /= 10;
        i++;
    }
    str = malloc(sizeof(char) * (i + 1));
    str[i] = '\0';
    while (--i >= 0) {
        str[i] = tmp % 10 + 48;
        tmp /= 10;
    }
    return (str);
}