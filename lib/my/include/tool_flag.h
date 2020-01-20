/*
** EPITECH PROJECT, 2019
** tool_flag
** File description:
** header for print
*/

#ifndef TOOL_FLAG_H_
#define TOOL_FLAG_H_

#include <stdarg.h>

void my_cflag(va_list *ap, const char *str, int i);

void my_dflag(va_list *ap, const char *str, int i);

void my_oflag(va_list *ap, const char *str, int i);

void my_sflag(va_list *ap, const char *str, int i);

void my_ssflag(va_list *ap, const char *str, int i);

void my_uflag(va_list *ap, const char *str, int i);

void my_xflag(va_list *ap, const char *str, int i);

void my_xxflag(va_list *ap, const char *str, int i);

void my_bflag(va_list *ap, const char *str, int i);

void my_pflag(va_list *ap, const char *str, int i);

void my_nflag(va_list *ap, const char *str, int i);

void my_percentflag(va_list *ap, const char *str, int i);

#endif
