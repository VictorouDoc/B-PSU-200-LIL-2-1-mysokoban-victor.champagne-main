/*
** EPITECH PROJECT, 2022
** my_sokoban
** File description:
** Sokoban Project 2022
*/

#include "include/my.h"

char *my_strcpy(char *dest, char const *src)
{
    int count = 0;

    for (; src[count] != '\0'; ++count)
        dest[count] = src[count];
    dest[count] = '\0';
    return dest;
}

void restart_map(char **tab, char **clone_tab, buffer_t *tmp)
{
    if (tmp->keyenter == 32) {
        for (int i = 0; clone_tab[i] != NULL; i++) {
            tab[i] = my_strcpy(tab[i], clone_tab[i]);
        }
        reset_to_zero(tmp);
    }
}

void reset_to_zero(buffer_t *tmp)
{
    tmp->i = tmp->stock_i;
    tmp->j = tmp->stock_j;
    clear();
    refresh();
}
