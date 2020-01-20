/*
** EPITECH PROJECT, 2019
** my_print_address
** File description:
** print address
*/

void my_put_ulong(unsigned long int nb, char *base, int sizebase);

int my_putstr(char const *str);

int my_put_address(void *ptr)
{
    my_putstr("0x");
    my_put_ulong((unsigned long int)ptr, "0123456789abcdef", 16);
    return (0);
}