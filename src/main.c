/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** shell
*/

#include "my.h"
#include "minishell.h"

static const int (*launch_builtin[])(char **, char **) = {
    change_directory,
    change_directory,
    change_directory,
    env,
    find_exec
};

int parse_input(char **input, char **env)
{
    int is_built = is_builtin(input);
    int i = 0;

    if (!input || (!my_strcmp(input[0], "exit") && !input[1])) {
        my_putstr("exit\n");
        free(input);
        return (0);
    }
    launch_builtin[is_built](input, env);
    while (input && input[i]) {
        free(input[i++]);
    }
    free(input);
    return (1);
}

int minishell(int ac, char **av , char **env)
{
    char *input = NULL;

    my_putstr("$> ");
    input = get_next_line(0);
    if (!parse_input(my_str_to_word_array(input, " \t"), env))
        return (0);
    if (input)
        free(input);
    minishell(ac, av, env);
    return (0);
}

int main(int ac, char **av, char **env)
{
    if (env == NULL)
        return (84);
    dup_env(env);
    minishell(ac, av, env);
    free_env(env);
    return (0);
}
