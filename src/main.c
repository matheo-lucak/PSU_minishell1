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
#include <stdio.h>

static int (*launch_builtin[])(char **, char ***);

void sigint_signal_gesture(int sig)
{
    if (!sig)
        return ;
    my_putchar('\n');
    my_putstr("\e[1;34m=\e[0m");
    prompt_pwd();
    my_putstr("\e[1;31m=> \e[0m");
    signal(SIGINT, sigint_signal_gesture);
}

int parse_input(char **input, char ***env)
{
    int is_built = is_builtin(input);
    int i = 0;
    int error = 1;

    if (!input)
        return (launch_builtin[is_built](input, env));
    if (!my_strncmp(input[0], "\n", 1))
        return (1);
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

    prompt();
x    input = get_next_line(0);
    if (!parse_input(my_str_to_word_array(input, " \t"), env))
        return (0);
    minishell(ac, av, env);
    return (0);
}

int init_minishell(int ac, char **av, char **env)
{
    char **new_env = dup_env(env);

    signal(SIGINT, sigint_signal_gesture);
    dup_env(env);
    minishell(ac, av, &new_env);
    signal(SIGINT, SIG_DFL);
    return (0);
}

int main(int ac, char **av, char **env)
{
    if (env == NULL)
        return (84);
    return (init_minishell(ac, av, env));
}
