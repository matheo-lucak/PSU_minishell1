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

int get_next_env_idx(char **env, int i)
{
    int env_idx = 0;

    if (!env)
        return (0);
    while (env[env_idx + i] && env[env_idx + i][0] == -1) {
        env_idx++;
    }
    return (env_idx + i);
}

void dup_unset_env(char **env)
{
    int env_idx = 0;

    while (env[env_idx]) {
        if (env[env_idx][0] == -1)
            env[env_idx] = env[get_next_env_idx(env, env_idx)];
        env_idx++;
    }
}

int unsetenv_error(char **env, char **input)
{
    if (!env || !input) {
        return (84);
    }
    if (input && input[0] && !input[1]) {
        my_printf("%s: Too few arguments.\n", input[0]);
        return (84);
    }
    return (0);
}

int unset_env(char **input, char ***env)
{
    int input_idx = 0;
    int env_idx = 0;
    int unseted_var_nb = 0;

    if (unsetenv_error(*env, input) == 84)
        return (84);
    while (input[input_idx]) {
        env_idx = find_env(*env, input[input_idx]);
        if (env_idx != -1) {
            (*env)[env_idx][0] = -1;
            unseted_var_nb++;
        }
        input_idx++;
    }
    dup_unset_env(*env);
    return (0);
}
