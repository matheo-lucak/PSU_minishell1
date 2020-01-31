/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** csflm rtfm
*/

#include <signal.h>
#include "my.h"
#include "minishell.h"

void exec_error(int child_status)
{
    int signal = WTERMSIG(child_status);

    if (!WIFSIGNALED(child_status))
        return ;
    if (signal == SIGSEGV)
        my_putstr("Segmentation fault");
    if (signal == SIGFPE)
        my_putstr("Floating exception");
    if ((signal == SIGSEGV  || signal == SIGFPE) && __WCOREDUMP(child_status))
        my_putstr(" (core dumped)");
    else if (__WCOREDUMP(child_status))
        my_putstr("Abort (core dumped)");
    my_putchar('\n');
}

int execve_error(char *bin_path)
{
    if (access(bin_path, X_OK) == -1) {
        my_printf("%s: Permission denied.\n", bin_path + 2);
        return (0);
    }
    return (1);
}

int my_exec(char **input, char *path, char **env)
{
    char * bin_path = set_new_path(path, input[0]);
    pid_t pid = -1;
    int child_status = 0;

    if (!execve_error(bin_path))
        return (84);
    pid = fork();
    if (pid == -1) {
        my_putstr("ERROR: Failed to spawn child process!\n");
        return (84);
    }
    if (!pid) {
        execve(bin_path, input, env);
    } else {
        waitpid(pid, &child_status, 0);
        exec_error(child_status);
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

int find_exec(char **input, char ***env)
{
    char **path = NULL;
    int path_idx = find_env(*env, "PATH=");
    int i = 0;

    if (path_idx == -1) {
        my_printf("%s: Command not found.\n", input[0]);
        return (84);
    }
    path = my_str_to_word_array((*env)[path_idx], "=:");
    if (!path)
        return (84);
    if (!my_strncmp(input[0], ".", 1) && open_fold(input, ".", *env))
            return (1);
    while (path[i]) {
        if (open_fold(input, path[i], *env))
            return (1);
        i++;
    }
    my_printf("%s: Command not found.\n", input[0]);
    return (1);
}