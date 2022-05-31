/*
** EPITECH PROJECT, 2022
** my_sokoban
** File description:
** Sokoban Project 2022
*/

#include "include/my.h"

int scan_map_victory(char **tab, buffer_t *tmp)
{
    for (int i = 0; tab[i] != NULL; i++) {
        for (int j = 0; tab[i][j] != '\n'; j++) {
            put_o(tab, tmp, i, j);
        }
    }
    return tmp->count;
}

void put_o(char **tab, buffer_t *tmp, int i, int j)
{
    if (tab[i][j] == 'O')
        tmp->count++;
    if (tab[i][j] == 'X')
        tmp->count_x++;
}
