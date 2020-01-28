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
}

void prompt(char **env)
{
    int fd = -1;

    fd = open(".git/HEAD", O_RDONLY);
    if (fd != -1) {
        prompt_git(fd);
        close(fd);
    }
}