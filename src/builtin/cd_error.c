/*
** EPITECH PROJECT, 2019
** cd command
** File description:
** change directory
*/

#include "my.h"
#include "minishell.h"
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>

int cd_error(char *input)
{
    struct stat stat_buff;

    if (!input)
        return (84);
    if (stat(input, &stat_buff) == -1) {
        my_printf("%s: No such file or directory.\n", input);
        return (84);
    }
    if (!S_ISDIR(stat_buff.st_mode)) {
        my_printf("%s: No such file or directory.\n", input);
        return (84);
    } else if (!access(input, X_OK) && !S_ISDIR(stat_buff.st_mode)) {
        my_printf("%s: Not a directory.\n", input);
        return (84);
    }
    return (1);
}
