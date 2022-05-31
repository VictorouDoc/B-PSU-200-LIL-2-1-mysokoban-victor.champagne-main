/*
** EPITECH PROJECT, 2022
** my_sokoban
** File description:
** Sokoban Project 2022
*/

#include "include/my.h"

void input_up(char **tab, buffer_t *tmp)
{
    if (tmp->keyenter == KEY_UP) {
        if (tab[tmp->i - 1][tmp->j] == 'X' &&
        (tab[tmp->i - 2][tmp->j] != '#' &&
        tab[tmp->i - 2][tmp->j] != 'X')) {
            tab[tmp->i][tmp->j] = ' ';
            tab[tmp->i - 1][tmp->j] = 'P';
            tab[tmp->i - 2][tmp->j] = 'X';
            tmp->i -= 1;
        }
        no_x_up(tab, tmp);
    }
}

void no_x_up(char **tab, buffer_t *tmp)
{
    if (tab[tmp->i - 1][tmp->j] != '#' &&
    tab[tmp->i - 1][tmp->j] != 'X') {
        tab[tmp->i][tmp->j] = ' ';
        tab[tmp->i - 1][tmp->j] = 'P';
        tmp->i -= 1;
    }
}

void input_down(char **tab, buffer_t *tmp)
{
    if (tmp->keyenter == KEY_DOWN) {
        if (tab[tmp->i + 1][tmp->j] == 'X' &&
        (tab[tmp->i + 2][tmp->j] != '#' &&
        tab[tmp->i + 2][tmp->j] != 'X')) {
            tab[tmp->i][tmp->j] = ' ';
            tab[tmp->i + 1][tmp->j] = 'P';
            tab[tmp->i + 2][tmp->j] = 'X';
            tmp->i += 1;
        }
        no_x_down(tab, tmp);
    }
}

void no_x_down(char **tab, buffer_t *tmp)
{
    if (tab[tmp->i + 1][tmp->j] != '#' &&
    tab[tmp->i + 1][tmp->j] != 'X') {
        tab[tmp->i][tmp->j] = ' ';
        tab[tmp->i + 1][tmp->j] = 'P';
        tmp->i += 1;
    }
}
