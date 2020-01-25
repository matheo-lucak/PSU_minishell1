/*
** EPITECH PROJECT, 2019
** cd command
** File description:
** change directory
*/

#include "my.h"
#include "minishell.h"
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>

void set_oldpwd(char **env, char *old_path)
{
    char *tmp = NULL;
    int i = find_env(env, "OLDPWD=");

    if (!my_strncmp("PWD=", old_path, my_strlen("PWD=")))
        tmp = my_strcat("OLDPWD=", old_path + my_strlen("PWD="));
    else if (!my_strncmp("OLDPWD=", old_path, my_strlen("OLDPWD=")))
        tmp = my_strcat("OLDPWD=", old_path + my_strlen("OLDPWD="));
    if (i == -1 || !old_path)
        return ;
    if (env[i]) {
        free(env[i]);
    }
    env[i] = tmp;
}
