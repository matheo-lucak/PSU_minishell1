/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** csflm rtfm
*/

#include "my.h"
#include "minishell.h"

int is_builtin(char **input)
{
    char *builtins[5] = {"cd", "setenv", "unsetenv", "env", NULL};
    int i = 0;

    if (!input || !input[0])
        return (-1);
    while (builtins[i]) {
        if (!my_strcmp(builtins[i], input[0]))
            return (i);
        i++;
    }
    return (-1);
}
