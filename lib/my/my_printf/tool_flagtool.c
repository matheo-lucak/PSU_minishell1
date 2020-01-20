/*
** EPITECH PROJECT, 2019
** tool_flag1
** File description:
** auxiliary func
*/

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <my.h>

void free_lenflag_pattern(char **arr)
{
    int i = 0;

    if (arr == NULL)
        return ;
    while (arr[i] != NULL) {
        free(arr[i]);
        i++;
    }
    free(arr);
}

int find_lenflag(char *str)
{
    int i = -1;
    char *strwordarr = "hh h l ll q j z";
    char **lenflag_pattern = my_str_to_word_array(strwordarr, " ");

    while (lenflag_pattern[++i])
        if (my_strncmp(lenflag_pattern[i], str, 2) == 0) {
            free(str);
            free_lenflag_pattern(lenflag_pattern);
            return (i);
        }
    free(str);
    free_lenflag_pattern(lenflag_pattern);
    return (-84);
}

int is_lenmodify(const char *str, int i)
{
    char *tmp_lenflag = malloc(sizeof(char) * 3);

    if (tmp_lenflag == NULL)
        return (0);
    while (str[i - 1] == 'h' || str[i - 1] == 'l' || str[i - 1] == 'q' ||
        str[i - 1] == 'j' || str[i - 1] == 'z')
        i--;
    if (str[i] == 'h' || str[i] == 'l' || str[i] == 'q' || str[i] == 'j' ||
        str[i] == 'z')
        tmp_lenflag[0] = str[i];
    else
        tmp_lenflag[0] = 'W';
    if (str[i + 1] == tmp_lenflag[0])
        tmp_lenflag[1] = str[i];
    tmp_lenflag[2] = '\0';
    return (find_lenflag(tmp_lenflag));
}
