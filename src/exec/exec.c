/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** csflm rtfm
*/

#include "my.h"
#include "minishell.h"

int my_exec(char **input, char *path, char **env)
{
    char * bin_path = set_new_path(path, input[0]);
    pid_t pid = -1;
    int child_status;

    pid = fork();
    if (pid == -1) {
        my_putstr("ERROR: Failed to spawn child process!\n");
        return (84);
    }
    if (!pid) {
        execve(bin_path, input, env);
    } else {
        waitpid(pid, &child_status, 0);
        free(bin_path);
    }
    return (1);
}

int find_env(char **env, char *str)
{
    int i = 0;

    while (env[i]) {
        if (!my_strncmp(str, env[i], my_strlen(str)))
            return (i);
        i++;
    }
    return (-1);
}

int find_exec(char **input, char **env)
{
    char **path = NULL;
    int path_idx = find_env(env, "PATH=");
    int i = 0;

    if (path_idx == -1)
        return (84);
    path = my_str_to_word_array(env[path_idx], "=:");
    if (!path)
        return (84);
    while (path[i]) {
        if (open_fold(input, path[i], env))
            return (1);
        i++;
    }
    my_printf("%s: Command not found.\n", input[0]);
    return (0);
}