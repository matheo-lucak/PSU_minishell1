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

char **dup_set_env(char **input, char **env, int var_nb)
{
    int i = 0;
    int j = 0;
    char **new_env = malloc(sizeof(char *) * (my_arrlen(env) + var_nb + 1));

    if (!new_env)
        return (NULL);
    while (env[i]) {
        new_env[i] = my_strdup(env[i]);
        i++;
    }
    while (j < var_nb) {
        new_env[i + j] = new_env_var(input, j + 1);
        j++;
    }
    new_env[i + j] = NULL;
    free_env(env);
    return (new_env);
}

int set_env(char **input, char ***env)
{
    int var_nb = 0;

    if (set_env_error(input, *env) == 84)
        return (84);
    var_nb = (my_arrlen(input) - 1) / 2;
    *env = dup_set_env(input, *env, var_nb);
    return (0);
}
