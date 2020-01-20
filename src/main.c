/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** csflm rtfm
*/

#include "my.h"
#include "minishell.h"

static const int (*launch_builtin[])(char **, char **) = {
    change_directory,
    change_directory,
    change_directory,
    env
};

int parse_input(char **input, char **env)
{
    int i = is_builtin(input);

    if (i != -1) {
        launch_builtin[i](input, env);
    } else if (input) {
        find_exec(input, env);
    }
    return (0);
}

int minishell(int ac, char **av , char **env)
{
    char *input = NULL;
    char **parsed_input = NULL;

    my_putstr("$> ");
    input = get_next_line(0);
    if (!input || !my_strcmp(input, "exit")) {
        my_putstr("exit\n");
        return (0);
    }
    parsed_input = my_str_to_word_array(input, " ");
    parse_input(parsed_input, env);
    minishell(ac, av, env);
    return (0);
}

void dup_env(char **env)
{
    int i = 0;

    if (!env)
        return ;
    while (env[i]) {
        env[i] = my_strdup(env[i]);
        i++;
    }
    env[i] = NULL;
}

int main(int ac, char **av, char **env)
{
    if (env == NULL)
        return (84);
    dup_env(env);
    minishell(ac, av, env);
    return (0);
}
