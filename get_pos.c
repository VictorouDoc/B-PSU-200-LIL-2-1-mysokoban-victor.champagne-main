/*
** EPITECH PROJECT, 2022
** my_sokoban
** File description:
** Sokoban Project 2022
*/

#include "include/my.h"

void get_pos(char **tab, buffer_t *tmp)
{
    for (int i = 0; tab[i] != NULL; i++) {
        for (int j = 0; tab[i][j] != '\0'; j++) {
            stock_pos(tab, tmp, i, j);
        }
    }
}

void stock_pos(char **tab, buffer_t *tmp, int i , int j)
{
    if (tab[i][j] == 'P') {
        tmp->i = i;
        tmp->j = j;
        tmp->stock_i = i;
        tmp->stock_j = j;
    }
}
