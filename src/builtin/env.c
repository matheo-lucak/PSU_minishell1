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

int env(char **input, char **env)
{
    if (input)
        input = input;
    if (!env)
        return (84);
    my_show_word_array(env);
    return (0);
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
