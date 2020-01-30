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

int is_in_env(char *input, char **env)
{
    char *tmp = my_strcat(input, "=");
    int idx = -1;

    if (!tmp || !input)
        return (idx);
    idx = find_env(env, tmp);
    return (idx);
}

char **dup_unsetenv(char **env, int unseted_var_nb)
{
    int i = 0;
    int j = 0;
    char **new_env = malloc(sizeof(char *) *
        (my_arrlen(env) - unseted_var_nb + 1));

    if (!env || !new_env)
        return (NULL);
    while (env[i]) {
        if (env[i][0] != -1) {
            new_env[j] = my_strdup(env[i]);
            j++;
        }
        i++;
    }
    new_env[j] = NULL;
    free_env(env);
    free(env);
    return (new_env);
}

int unset_env(char **input, char ***env)
{
    int input_idx = 1;
    int env_idx = 0;
    int unseted_var_nb = 0;

    if (unsetenv_error(*env, input) == 84)
        return (84);
    while (input[input_idx]) {
        env_idx = is_in_env(input[input_idx], *env);
        if (env_idx != -1) {
            (*env)[env_idx][0] = -1;
            unseted_var_nb++;
        }
        input_idx++;
    }
    *env = dup_unsetenv(*env, unseted_var_nb);
    return (1);
}
