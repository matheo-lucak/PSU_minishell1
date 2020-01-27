/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** csflm rtfm
*/

#include "my.h"
#include "minishell.h"

int exit_minishell(char **input, char ***env)
{
    (void)env;
    if (input && input[0] && input[1]) {
        my_printf("%s: Expression Syntax.\n", input[0]);
        return (0);
    }
    my_printf("exit\n");
    return (0);
}