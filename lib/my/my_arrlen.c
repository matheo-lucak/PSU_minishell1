/*
** EPITECH PROJECT, 2019
** my_arrlen
** File description:
** len of an array
*/

int my_arrlen(char **str)
{
    int str_nbr = 0;

    while (str && str[str_nbr] != 0)
        str_nbr += 1;
    return (str_nbr);
}
