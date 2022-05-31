/*
** EPITECH PROJECT, 2022
** my_sokoban
** File description:
** Sokoban Project 2022
*/

#include "include/my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

char *my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; ++i) {
        my_putchar(str[i]);
    }
    return (0);
}

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}

void print_tab(char **tabl)
{
    for (int i = 0; tabl[i] != NULL; i++) {
        write(1, tabl[i], my_strlen(tabl[i]));
        write(1, "\n", 1);
    }
}

char *my_strcat(char *dest, char *src)
{
    int i = 0;
    int len_str = my_strlen(dest) + my_strlen(src);
    char *str = malloc(sizeof(char) * (len_str + 1));

    for (; i < my_strlen(dest); i++)
        str[i] = dest[i];
    for (int j = 0; j < my_strlen(src); j++) {
        str[i] = src[j];
        i++;
    }
    str[len_str] = '\0';
    return str;
}
