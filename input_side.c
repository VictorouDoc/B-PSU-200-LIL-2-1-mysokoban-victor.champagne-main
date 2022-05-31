/*
** EPITECH PROJECT, 2022
** my_sokoban
** File description:
** Sokoban Project 2022
*/

#include "include/my.h"

void input_left(char **tab, buffer_t *tmp)
{
    if (tmp->keyenter == KEY_LEFT) {
        if (tab[tmp->i][tmp->j - 1] == 'X' &&
        (tab[tmp->i][tmp->j - 2] != '#' &&
        tab[tmp->i][tmp->j - 2] != 'X')) {
            tab[tmp->i][tmp->j] = ' ';
            tab[tmp->i][tmp->j - 1] = 'P';
            tab[tmp->i][tmp->j - 2] = 'X';
            tmp->y -= 1;
        }
        no_x_left(tab, tmp);
    }
}

void no_x_left(char **tab, buffer_t *tmp)
{
    if (tab[tmp->i][tmp->j - 1] != '#' &&
    tab[tmp->i][tmp->j - 1] != 'X') {
        tab[tmp->i][tmp->j] = ' ';
        tab[tmp->i][tmp->j - 1] = 'P';
        tmp->j -= 1;
    }
}

void input_right(char **tab, buffer_t *tmp)
{
    if (tmp->keyenter == KEY_RIGHT) {
        if (tab[tmp->i][tmp->j + 1] == 'X' &&
        (tab[tmp->i][tmp->j + 2] != '#' &&
        tab[tmp->i][tmp->j + 2] != 'X')) {
            tab[tmp->i][tmp->j] = ' ';
            tab[tmp->i][tmp->j + 1] = 'P';
            tab[tmp->i][tmp->j + 2] = 'X';
            tmp->y += 1;
        }
        no_x_right(tab, tmp);
    }
}

void no_x_right(char **tab, buffer_t *tmp)
{
    if (tab[tmp->i][tmp->j + 1] != '#' &&
    tab[tmp->i][tmp->j + 1] != 'X') {
        tab[tmp->i][tmp->j] = ' ';
        tab[tmp->i][tmp->j + 1] = 'P';
        tmp->j += 1;
    }
}
