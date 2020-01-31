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

int env(char **input, char ***env)
{
    if (input)
        input = input;
    if (!(*env))
        return (84);
    my_show_word_array(*env);
    return (1);
}

void free_env(char **env)
{
    int i = 0;

    if (!env)
        return ;
    while (env[i]) {
        free(env[i]);
        i++;
    }
}

char **dup_env(char **env)
{
    char **new_env = NULL;
    int i = 0;

    if (!env)
        return (NULL);
    new_env = malloc(sizeof(char *) * (my_arrlen(env) + 1));
    while (env[i]) {
        new_env[i] = my_strdup(env[i]);
        i++;
    }
    new_env[i] = NULL;
    return (new_env);
}

int find_env(char **env, char *str)
{
    int i = 0;

    while (env[i]) {
        if (!my_strncmp(str, env[i], my_strlen(str)))
            return (i);
        i++;
    }
    return (-1);
}
