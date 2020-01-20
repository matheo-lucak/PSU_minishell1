/*
** EPITECH PROJECT, 2019
** my_show_word_array
** File description:
** displays the content of an array of words
*/
#include <stdlib.h>

int my_putstr(char const *str);

int my_show_word_array(char * const *tab)
{
    int i = 0;

    if (tab == NULL)
        return (84);
    while (tab[i] != NULL) {
        my_putstr(tab[i]);
        my_putstr("\n");
        i += 1;
    }
    return (0);
}
