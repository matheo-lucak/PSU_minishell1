/*
** EPITECH PROJECT, 2019
** get_map
** File description:
** get_map func
*/

#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include "my.h"

int is_end_of_line(char *buffer)
{
    int i = 0;

    while (buffer[i] != '\0') {
        if (buffer[i] == '\n')
            return (1);
        i++;
    }
    return (0);
}

char *my_strdup_line(char *buffer)
{
    char *line = NULL;
    int i = 0;

    if (buffer && buffer[0] == '\n')
        return (my_strdup("\n"));
    while (buffer[i] != '\0' && buffer[i] != '\n')
        i++;
    line = my_strndup(buffer, i);
    return (line);
}

char *re_alloc_buffer(char *buffer, char *stock, int mode)
{
    char *new_buffer = NULL;
    int i = 0;

    if (mode) {
        new_buffer = my_strcat(buffer, stock);
        free(buffer);
        return (new_buffer);
    }
    while (buffer[i + 1] != '\0' && buffer[i + 1] != '\n')
        i++;
    if (buffer[i + 1] == '\0')
        return (NULL);
    new_buffer = my_strdup(buffer + i + 2);
    free(buffer);
    return (new_buffer);
}

char *add_in_buffer(int fd, char *buffer, int *rd)
{
    char stock[128 + 1];

    if (stock == NULL || buffer == NULL)
        return (NULL);
    while (!is_end_of_line(buffer) && *rd != 0) {
        *rd = read(fd, stock, 128);
        if (*rd == -1)
            return (NULL);
        stock[*rd] = '\0';
        buffer = re_alloc_buffer(buffer, stock, 1);
    }
    return (buffer);
}

char *get_next_line(int fd)
{
    static char *buffer = NULL;
    char *line = NULL;
    int rd = 1;

    if (buffer == NULL)
        buffer = my_strdup("\0");
    if (fd == -1)
        return (NULL);
    buffer = add_in_buffer(fd, buffer, &rd);
    if (buffer == NULL || (buffer[0] == '\0' && rd == 0))
        return (NULL);
    line = my_strdup_line(buffer);
    buffer = re_alloc_buffer(buffer, buffer, 0);
    return (line);
}
