/*
** EPITECH PROJECT, 2022
** my_sokoban
** File description:
** Sokoban Project 2022
*/

#include "include/my.h"

void lose_check(char **tab, char **clone_tab, buffer_t *tmp, int i)
{
    for (int j = 0; tab[i][j] != '\0'; j++) {
        if ((tab[i][j] == 'X' && clone_tab[i][j] != '0') &&
        ((tab[i + 1][j] == '#' && tab[i][j + 1] == '#') ||
        (tab[i + 1][j] == '#' && tab[i][j - 1] == '#') ||
        (tab[i][j - 1] == '#' && tab[i + 1][j] == '#') ||
        (tab[i][j - 1] == '#' && tab[i - 1][j] == '#') ||
        (tab[i][j + 1] == '#' && tab[i - 1][j] == '#'))) {
            tmp->count_sx++;
        }
    }
    cond_end(tmp);
}

void cond_end(buffer_t *tmp)
{
    if (tmp->count_x == tmp->count_sx) {
        endwin();
        my_putstr("You lose !\n");
        exit(1);
    }
}
