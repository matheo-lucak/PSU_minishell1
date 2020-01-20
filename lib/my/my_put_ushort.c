/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** displays the number given as parameter
*/

void my_putchar(char c);

void my_put_ushort(unsigned short nb, char *base, int sizebase)
{
    if (nb / sizebase > 0)
        my_put_ushort(nb / sizebase, base, sizebase);
    my_putchar(base[nb % sizebase]);
}