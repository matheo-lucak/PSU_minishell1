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
    my_printf("[\e[1;36m%s\e[0m]", parsed_str[my_arrlen(parsed_str) - 1]);
    free_env(parsed_str);
    free(str);
    free(parsed_str);
}

void prompt_pwd(void)
{
    char cwd[4096];
    char **parsed_pwd = NULL;

    getcwd(cwd, 4096);
    parsed_pwd = my_str_to_word_array(cwd, "/");
    if (!parsed_pwd)
        return ;
    my_printf("[\e[1;32m%s\e[0m]", parsed_pwd[my_arrlen(parsed_pwd) - 1]);
    free_env(parsed_pwd);
    free(parsed_pwd);
}

void prompt(void)
{
    int fd = -1;

    my_putstr("\e[1;34m=\e[0m");
    prompt_pwd();
    fd = open(".git/HEAD", O_RDONLY);
    if (fd != -1) {
        prompt_git(fd);
        close(fd);
    }
    my_putstr("\e[1;31m=> \e[0m");
    }