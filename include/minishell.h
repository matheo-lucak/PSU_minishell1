/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** minishell header file
*/

#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>

int find_env(char **env, char *str);
int find_exec(char **input, char **env);
int open_fold(char **input, char *path, char **env);
int my_exec(char **command, char *path, char **env);
char *set_new_path(char *path, char *dir_name);

int is_builtin(char **input);
int change_directory(char **input, char **env);
void set_oldpwd(char **env, char *old_path);
int env(char **input, char **env);
void clean_path(char **env);

void free_env(char **env);
void dup_env(char **env);


#endif
