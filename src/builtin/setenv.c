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

char *new_env_var(char **input)
{
    char *tmp1 = NULL;
    char *tmp2 = NULL;

    if (!input || !input[0] || !input[1])
        return (NULL);
    tmp1 = my_strcat(input[1], "=");
    if (!tmp1)
        return (NULL);
    if (my_arrlen(input) == 2)
        return (tmp1);
    tmp2 = my_strcat(tmp1, input[2]);
    free(tmp1);
    return (tmp2);
}

char **dup_set_env(char **input, char **env)
{
    int i = 0;
    char **new_env = malloc(sizeof(char *) * (my_arrlen(env) + 2));

    if (!new_env || !env)
        return (NULL);
    while (env[i]) {
        new_env[i] = my_strdup(env[i]);
        i++;
    }
    if (find_env(env, input[1]) == -1)
        new_env[i] = new_env_var(input);
    else {
        new_env[find_env(env, input[1])] = new_env_var(input);
        new_env[i] = NULL;
    }
    new_env[i + 1] = NULL;
    free_env(env);
    free(env);
    return (new_env);
}

int set_env(char **input, char ***env)
{
    if (!input || !env)
        return (84);
    if (my_arrlen(input) == 1) {
        my_show_word_array(*env);
        return (1);
    }
    if (set_env_error(input) == 84)
        return (84);
    *env = dup_set_env(input, *env);
    return (1);
}
