/*
** EPITECH PROJECT, 2019
** my
** File description:
** my header file
*/

#ifndef MY_H
#define MY_H

int my_arrlen(char **str);
int my_getnbr(char *nb_str);
char *my_int_to_str(int nb);
void my_memset(char *str, char c, int len);
int my_pow(int nb, int p);
float my_powf(float nb, float p);
int my_put_address(void *ptr);
void my_put_char(char nb, char *base, int sizebase);
void my_put_int(int nb, char *base, int sizebase);
void my_put_long_long(long long nb, char *base, int sizebase);
void my_put_long(long nb, char *base, int sizebase);
void my_put_short(short nb, char *base, int sizebase);
void my_put_uchar(unsigned char nb, char *base, int sizebase);
void my_put_uint(unsigned int nb, char *base, int sizebase);
void my_put_ulong_long(unsigned long long nb, char *base, int sizebase);
void my_put_ulong(unsigned long int nb, char *base, int sizebase);
void my_put_ushort(unsigned short nb, char *base, int sizebase);
void my_putchar(char c);
int my_putstr(char const *str);
int my_show_word_array(char * const *tab);
char **my_str_to_word_array(char const *str, char *sep);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char *s1, char *s2);
char *my_strcpy(char *dest, char const *src);
char *my_strdup(char *src);
int my_strlen(char const *str);
char *my_strncat(char *dest, char const *src, int n);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strncpy(char *dest, char const *src, int n);

int my_printf(const char *src, ...);
char *get_next_line(int fd);

#endif
