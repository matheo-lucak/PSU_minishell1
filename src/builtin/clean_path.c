/*
** EPITECH PROJECT, 2019
** clean_path
** File description:
** path cleaner
*/

#include "my.h"
#include "minishell.h"

void clean_last_bracket(char **path)
{
    char *tmp = NULL;

    if (!path || !(*path))
        return ;
    while ((*path)[my_strlen(*path) - 1] == '/') {
        tmp = my_strndup(*path, my_strlen(*path) - 1 );
        if (*path)
            free(*path);
        *path = tmp;
    }
}

void clean_point_dir(char **path)
{
    char *tmp = NULL;
    char *tmp2 = NULL;
    int i = 0;

    if (!path || !(*path))
        return ;
    i = my_hay_needle(*path, "/./");
    if (!i)
        return ;
    tmp = my_strndup((*path), i);
    tmp2 = my_strdup((*path) + i + 2);
    free(*path);
    if (!tmp || !tmp2)
        return ;
    *path = my_strcat(tmp, tmp2);
    free(tmp);
    free(tmp2);
}

void clean_parent_dir(char **path)
{
    char *tmp = NULL;
    char *tmp2 = NULL;
    int i = 0;


    if (!path || !(*path))
        return ;
    i = my_hay_needle(*path, "/..") - 1;
    if (!i)
        return ;
    tmp2 = my_strdup((*path) + i + 4);
    while ((*path)[i] && (*path)[i] != '/')
        i--;
    tmp = my_strndup(*path, i);
    if (!tmp || !tmp2)
        return ;
    free(*path);
    *path = my_strcat(tmp, tmp2);
}

int is_clean(char *path)
{
    if (!path)
        return  (84);
    if (my_hay_needle(path, "/./"))
        return (0);
    if (my_hay_needle(path, "/.."))
        return  (0);
    return  (1);
}

char *clean_path(char *path)
{
    if (!path)
        return (NULL);
    while (!is_clean(path)) {
        clean_point_dir(&path);
        clean_parent_dir(&path);
    }
        clean_last_bracket(&path);
    return  (path);
}
