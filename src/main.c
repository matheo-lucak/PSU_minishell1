/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** shell
*/

#include <signal.h>
#include "my.h"
#include "minishell.h"
#include "builtin.h"

static int (*launch_builtin[])(char **, char ***);

void sigint_signal_gesture(int sig)
{
    my_putstr("\n$> ");
    signal(SIGINT, sigint_signal_gesture);
}

int parse_input(char **input, char ***env)
{
    int is_built = is_builtin(input);
    int i = 0;
    int error = 1;

    error = launch_builtin[is_built](input, env);
    while (input && input[i]) {
        free(input[i++]);
    }
    if (input)
        free(input);
    return (error);
}

int minishell(int ac, char **av , char ***env)
{
    char *input = NULL;

    my_putstr("$> ");
    input = get_next_line(0);
    if (!parse_input(my_str_to_word_array(input, " \t"), env))
        return (0);
    minishell(ac, av, env);
    return (0);
}

int main(int ac, char **av, char **env)
{
    if (env == NULL)
        return (84);
    signal(SIGINT, sigint_signal_gesture);
    dup_env(env);
    minishell(ac, av, &env);
    free_env(env);
    signal(SIGINT, SIG_DFL);
    return (0);
}
