/*
** EPITECH PROJECT, 2019
** my_putchar
** File description:
** displays one char
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
