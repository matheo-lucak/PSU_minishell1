/*
** EPITECH PROJECT, 2019
** env
** File description:
** func for env
*/

#include "my.h"
#include "minishell.h"
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>

int set_env_count_brackets(char *input)
{
    int i = 0;
    int bracket_idx = 0;

    while (input[i]) {
        if (input[i] == '(')
            bracket_idx++;
        else if (input[i] == ')')
            bracket_idx++;
        i++;
    }
    if (bracket_idx > 0) {
        my_putstr("Too many ('s.\n");
        return (84);
    }
    if (bracket_idx < 0) {
        my_putstr("Too many )'s.\n");
        return (84);
    }
    return (0);
}

int set_env_alphnum_error(char *input)
{
    int i = 0;

    while (input[i]) {
        if (!my_is_alpha_num(input[i]) &&
            input[i] != '(' && input[i] != ')') {
            my_putstr("setenv: Variable name must "\
            "contain alphanumeric characters.\n");
            return (84);
        }
        i++;
    }
    return (0);
}

int set_env_error(char **input, char **env)
{
    if (!input || !env)
        return (84);
    if (my_arrlen(input) > 3) {
        my_printf("%s: Too many arguments.\n", input[0]);
        return (84);
    }
    if (!my_is_alpha(input[1][0]) && !my_is_caps_alpha(input[1][0])) {
        my_putstr("setenv: Variable name must begin with a letter.\n");
        return (84);
        }
    if (set_env_alphnum_error(input[1]) == 84 ||
        set_env_count_brackets(input[1]) == 84)
        return (84);
    return (0);
}
