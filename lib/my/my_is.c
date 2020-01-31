/*
** EPITECH PROJECT, 2019
** env
** File description:
** func for env
*/

#include "my.h"

int my_is_num(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

int my_is_alpha(char c)
{
    if (c >= 'a' && c <= 'z')
        return (1);
    return (0);
}

int my_is_caps_alpha(char c)
{
    if (c >= 'A' && c <= 'Z')
        return (1);
    return (0);
}

int my_is_alpha_num(char c)
{
    if (my_is_num(c) ||
        my_is_alpha(c) ||
        my_is_caps_alpha(c))
        return (1);
    return (0);
}