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

int back_cd(char **env)
{
    char *tmp1 = NULL;
    char *tmp2 = NULL;
    int j = find_env(env, "PWD=");
    int i = find_env(env, "OLDPWD=");

    if (i == -1 || j == -1)
        return (84);
    tmp1 = my_strcat("OLDPWD=", env[j] + 4);
    tmp2 = my_strcat("PWD=", env[i] + 7);
    if (env[j])
        free(env[j]);
    set_oldpwd(env, tmp1);
    env[j] = tmp2;
    chdir(env[j] + 4);
    return (0);
}