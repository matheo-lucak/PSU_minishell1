/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** minishell header file
*/

#ifndef FUNCPTR_H
#define FUNCPTR_H

int env(char **input, char ***env);
int set_env(char **input, char ***env);
int unset_env(char **input, char ***env);
int change_directory(char **input, char ***env);
int find_exec(char **input, char ***env);

static int (*launch_builtin[])(char **, char ***) = {
    change_directory,
    set_env,
    unset_env,
    env,
    find_exec
};

#endif
