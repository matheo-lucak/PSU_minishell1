/*
** EPITECH PROJECT, 2019
** my_compute_power_rec
** File description:
** returns the first argument raised to the second given argument
*/

int my_pow(int nb, int p)
{
    if (p == 0)
        return (1);
    if (p < 0)
        return (0);
    nb *= my_pow(nb, p - 1);
    return (nb);
}

float my_powf(float nb, float p)
{
    if (p == 0)
        return (1);
    if (p < 0)
        return (0);
    nb *= my_powf(nb, p - 1);
    return (nb);
}