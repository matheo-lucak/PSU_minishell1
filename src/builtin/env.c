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
    if (!env)
        return (84);
    my_show_word_array(env);
    return (0);
}