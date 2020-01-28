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

int set_env_error(char **input, char **env)
{
    if (!input || !env)
        return (84);
    if (my_arrlen(input) % 2 == 0) {
        my_printf("%ssetenv: Too many arguments.\n", input[0]);
        return (84);
    }
    return (0);
}

char *new_env_var(char **input, int i)
{
    char *tmp1 = NULL;
    char *tmp2 = NULL;

    if (!input)
        return (NULL);
    if (!input[i] || !input[i + 1])
        return (NULL);
    tmp1 = my_strcat(input[i], "=");
    if (!tmp1)
        return (NULL);
    tmp2 = my_strcat(tmp1, input[i + 1]);
    free(tmp1);
    return (tmp2);
}

void set_newenv_var(char **input, char **new_env, char **env, int i)
{
    int j = 0;
    int shift_j = 0;
    int var_nb = (my_arrlen(input) - 1) / 2;
    int env_idx = 0;

    while (j < var_nb) {
        env_idx = find_env(env, input[j * 2 + 1]);
        if (env_idx != -1) {
            new_env[env_idx] = new_env_var(input, j * 2 + 1);
            shift_j--;
        } else
            new_env[i + j + shift_j] = new_env_var(input, j * 2 + 1);
        j++;
    }
    new_env[i + j + shift_j] = NULL;
}

char **dup_set_env(char **input, char **env)
{
    int i = 0;
    char **new_env = malloc(sizeof(char *) * (my_arrlen(env) +
        (my_arrlen(input) - 1) / 2 + 1));

    if (!new_env)
        return (NULL);
    while (env[i]) {
        new_env[i] = my_strdup(env[i]);
        i++;
    }
    set_newenv_var(input, new_env, env, i);
    free_env(env);
    return (new_env);
}

int set_env(char **input, char ***env)
{
    if (set_env_error(input, *env) == 84)
        return (84);
    *env = dup_set_env(input, *env);
    return (1);
}
