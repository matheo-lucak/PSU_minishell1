/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** displays the number given as parameter
*/

void my_putchar(char c);

void my_put_long_long(long long nb, char *base, int sizebase)
{
    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    }
    if (nb / sizebase > 0)
        my_put_long_long(nb / sizebase, base, sizebase);
    my_putchar(base[nb % sizebase]);
}