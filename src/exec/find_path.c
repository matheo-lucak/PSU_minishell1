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

int read_fold(char **input, DIR *dir, char *path, char **env)
{
    struct dirent *dirent = NULL;

    dirent = readdir(dir);
    while (dirent != NULL) {
        if (dirent->d_type != 4 &&
            !my_strcmp(dirent->d_name, input[0])) {
            my_exec(input, path, env);
            return (1);
            }
        dirent = readdir(dir);
    }
    closedir(dir);
    return (0);
}

int open_fold(char **input, char *path, char **env)
{
    DIR *dir = NULL;

    if (!path)
        return (84);
    dir = opendir(path);
    if (dir)
        if (read_fold(input, dir, path, env))
        return (1);
    return (0);
}