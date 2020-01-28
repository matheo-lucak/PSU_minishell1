/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** minishell header file
*/

#ifndef MINISHELL_H
#define MINISHELL_H

#define UNUSED(x) (void *)x

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>

int find_env(char **env, char *str);
int open_fold(char **input, char *path, char **env);
int my_exec(char **command, char *path, char **env);
char *set_new_path(char *path, char *dir_name);
void prompt(char **env);

int is_builtin(char **input);

void set_oldpwd(char **env, char *old_path);
void clean_path(char **env);

void free_env(char **env);
void dup_env(char **env);

#endif
