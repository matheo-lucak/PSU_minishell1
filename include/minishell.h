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
void prompt(void);
void prompt_pwd(void);

int is_builtin(char **input);

void set_oldpwd(char **env, char *old_path);
void clean_path(char **env);
int set_env_error(char **input);
int cd_error(char *input);
int back_cd(char **env);
int raw_exec(char **input, char **env);

void free_env(char **env);
char **dup_env(char **env);

#endif
