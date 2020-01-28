/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** csflm rtfm
*/

#include "my.h"
#include "minishell.h"

void prompt_git(int fd)
{
    char *str = get_next_line(fd);
    char **parsed_str = my_str_to_word_array(str, "/");

    if (!str || !parsed_str)
        return ;
    my_printf("[\e[0;36m%s\e[0m]", parsed_str[my_arrlen(parsed_str) - 1]);
    free_env(parsed_str);
    free(str);
    free(parsed_str);
}

void prompt_pwd(char **env)
{
    int pwd_idx = find_env(env, "PWD");
    char **parsed_pwd = NULL;

    if (pwd_idx == -1 || !env[pwd_idx])
        return ;
    parsed_pwd = my_str_to_word_array(env[pwd_idx], "/");
    if (!parsed_pwd)
        return ;
    my_printf("[\e[0;32m%s\e[0m]", parsed_pwd[my_arrlen(parsed_pwd) - 1]);
    free_env(parsed_pwd);
    free(parsed_pwd);
}

void prompt(char **env)
{
    int fd = -1;

    my_putstr("\e[1;34m\u039E\e[0m");
    prompt_pwd(env);
    fd = open(".git/HEAD", O_RDONLY);
    if (fd != -1) {
        prompt_git(fd);
        close(fd);
    }
    my_putstr("\e[1;31m\u039E> \e[0m");
}