/*
** EPITECH PROJECT, 2019
** 
** File description:
** 
*/

#include "my.h"
#include "minishell.h"
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>

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
    if (env[i])
        free(env[i]);
    if (env[j])
        free(env[j]);
    env[i] = tmp1;
    env[j] = tmp2;
    chdir(env[j] + 4);
    return (0);
}

int regular_cd(char *path, char **env)
{
    int i = find_env(env, "PWD");

    if (i == -1)
        return (84);
    env[i] = set_new_path(env[i], path);
    chdir(env[i] + 4);
    return (0);
}

int cd_home(char **env)
{
    int i = find_env(env, "PWD");
    int j = find_env(env, "USER");
    char *tmp = NULL;

    if (i == -1 || j == -1)
        return (84);
    tmp = my_strcat("PWD=/home/", env[j] + my_strlen("USER="));
    free(env[i]);
    env[i] = tmp;
    chdir(env[i] + 4);
    return (0);
}

int special_cd(char **input, char **env)
{
    if (input[0] && !input[1]) {
        cd_home(env);
        return (1);
    }
    if (input[1] && !my_strcmp(input[1], "-")) {
        back_cd(env);
        return (1);
    }
    return (0);
}

int change_directory(char **input, char **env)
{
    DIR *dir = NULL;

    if (my_arrlen(input) > 2) {
        my_printf("cd: Too few arguments\n");
        return (84);
    }
    if (!input || !input[0])
        return (84);
    if (special_cd(input, env))
        return (0);
    dir = opendir(input[1]);
    if (dir) {
        regular_cd(input[1], env);
        closedir(dir);
    } else
        my_printf("%s: No such file or directory.\n", input[1]);
    return (0);
}
