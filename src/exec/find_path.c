/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** csflm rtfm
*/

#include "my.h"
#include "minishell.h"

char *set_new_path(char *path, char *dir_name)
{
    char *new_path = NULL;
    char *tmp_path = NULL;

    tmp_path = my_strcat(path, "/");
    if (!tmp_path || !dir_name)
        return (NULL);
    new_path = my_strcat(tmp_path, dir_name);
    free(tmp_path);
    if (!new_path)
        return (NULL);
    return (new_path);
}

static int is_folder(char *input, struct dirent *dirent)
{
    if (dirent->d_type == 4) {
        my_printf("%s: Permission denied.\n", input);
        return (0);
    }
    return (1);
}

int read_fold(char **input, DIR *dir, char *path, char **env)
{
    struct dirent *dirent = NULL;

    dirent = readdir(dir);
    if (!input)
        return (0);
    while (dirent != NULL) {
        if ((!my_strcmp(dirent->d_name, input[0]) ||
            (!my_strcmp(dirent->d_name, input[0] + 2) &&
            !my_strncmp(input[0], "./", 2))) &&
            is_folder(input[0], dirent)) {
            my_exec(input, path, env);
            return (1);
            }
        dirent = readdir(dir);
    }
    closedir(dir);
    return (0);
}

int raw_exec(char **input, char **env)
{
    int i = my_strlen(*input) - 1;
    char *tmp = NULL;
    int error = 0;

    if (input[0][0] != '/')
        return (0);
    while (input[0][i] != '/') {
        i--;
    }
    tmp = my_strndup(input[0], i);
    input[0] = my_strdup(input[0] + i + 1);
    error = open_fold(input, tmp, env);
    free(tmp);
    return (error);
}

int open_fold(char **input, char *path, char **env)
{
    DIR *dir = NULL;

    if (!path || !input)
        return (0);
    dir = opendir(path);
    if (dir) {
        return (read_fold(input, dir, path, env));
    }
    return (0);
}