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

int absolute_cd(char *path, char **env)
{
    char *tmp = NULL;
    int i = find_env(env, "PWD");

    if (i == -1)
        return (84);
    set_oldpwd(env, env[i]);
    tmp = set_new_path("PWD=", path);
    if (env[i])
        free(env[i]);
    env[i] = tmp;
    chdir(env[i] + 4);
    return (0);
}

int regular_cd(char *path, char **env)
{
    char *tmp = NULL;
    int i = find_env(env, "PWD");

    if (i == -1)
        return (84);
    set_oldpwd(env, env[i]);
    tmp = set_new_path(env[i], path);
    if (env[i])
        free(env[i]);
    env[i] = tmp;
    chdir(env[i] + 4);
    return (0);
}

int cd_home(char **env, char *input)
{
    int i = find_env(env, "PWD");
    int j = find_env(env, "HOME");
    char *tmp = NULL;

    if (i == -1 || j == -1)
        return (84);
    set_oldpwd(env, env[i]);
    tmp = my_strcat("PWD=", env[j] + my_strlen("HOME="));
    if (input)
        tmp = my_strcat(tmp, input + 1);
    if (cd_error(tmp + my_strlen("PWD=")) == 84)
        return (84);
    free(env[i]);
    env[i] = tmp;
    chdir(env[i] + 4);
    clean_path(env);
    return (0);
}

int special_cd(char **input, char **env)
{
    if (input[0] && (!input[1] || !my_strncmp(input[1], "~", 1))) {
        cd_home(env, input[1]);
        clean_path(env);
        return (1);
    }
    if (input[1] && !my_strcmp(input[1], "-")) {
        back_cd(env);
        clean_path(env);
        return (1);
    }
    if (input[1] && !my_strncmp(input[1], "/", 1) && cd_error(input[1]) != 84) {
        absolute_cd(input[1], env);
        clean_path(env);
        return (1);
    }
    return (0);
}

int change_directory(char **input, char ***env)
{
    if (my_arrlen(input) > 2) {
        my_printf("cd: Too few arguments\n");
        return (84);
    }
    if (!input || !input[0])
        return (84);
    if (special_cd(input, *env))
        return (1);
    if (cd_error(input[1]) != 84) {
        regular_cd(input[1], *env);
        clean_path(*env);
    }
    return (1);
}
