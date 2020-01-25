/*
** EPITECH PROJECT, 2019
** clean_path
** File description:
** path cleaner
*/

#include "my.h"
#include "minishell.h"

char *cat_new_path_from_arr(char **parsed_path)
{
    char *tmp = NULL;
    char *new_path = NULL;
    int i = 1;

    new_path = my_strdup(parsed_path[0]);
    if (!new_path)
        return (NULL);
    while (parsed_path[i]) {
        if (parsed_path[i][0] != -1) {
            tmp = set_new_path(new_path, parsed_path[i]);
            free(new_path);
            new_path = my_strdup(tmp);
            free(tmp);
        }
        free(parsed_path[i]);
        i++;
    }
    free(parsed_path);
    return (new_path);
}

void set_parsed_back_cd(char **parsed_path, int i)
{
    parsed_path[i][0] = -1;
    while (parsed_path[i][0] == -1 && i > 0) {
        i--;
    }
    if (i > 0) {
        parsed_path[i][0] = -1;
    }
}

char *parse_and_clean(char *path)
{
    char **parsed_path = NULL;
    int i = 1;

    if (!path)
        return (NULL);
    parsed_path = my_str_to_word_array(path, "/");
    if (!parsed_path)
        return (NULL);
    while (parsed_path[i]) {
        if (!my_strcmp(parsed_path[i], "..")) {
            set_parsed_back_cd(parsed_path, i);
        } else if (!my_strcmp(parsed_path[i], ".")) {
            parsed_path[i][0] = -1;
        }
        i++;
    }
    return (cat_new_path_from_arr(parsed_path));
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

void clean_path(char **env)
{
    int i = find_env(env, "PWD=");
    int j = find_env(env, "OLDPWD=");
    char *tmp = NULL;

    if (i != -1 && !is_clean(env[i])) {
        tmp = parse_and_clean(env[i]);
        free(env[i]);
        env[i] = my_strdup(tmp);
        free(tmp);
    }
    if (j != -1 && !is_clean(env[j])) {
        tmp = parse_and_clean(env[j]);
        free(env[j]);
        env[j] = my_strdup(tmp);
        free(tmp);
    }
}
