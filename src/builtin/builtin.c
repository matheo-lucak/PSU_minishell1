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
    char *builtins[6] = {"cd", "setenv", "unsetenv", "env", "exit", NULL};
    int i = 0;

    if (!input || !input[0])
        return (4);
    while (builtins[i]) {
        if (!my_strcmp(builtins[i], input[0]))
            return (i);
        i++;
    }
    return (i);
}