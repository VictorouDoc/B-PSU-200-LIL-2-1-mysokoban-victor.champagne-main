/*
** EPITECH PROJECT, 2022
** my_sokoban
** File description:
** Sokoban Project 2022
*/

#include "include/my.h"

void foro(char **clone_tab, char **tab, buffer_t *tmp)
{
    for (int i = 0; tab[i] != NULL; i++) {
        for (int j = 0; tab[i][j] != '\n'; j++) {
            place_o(tab, clone_tab, i, j);
            win_cond(tmp, tab);
        }
    }
    tmp->count_sx = 0;
    tmp->count_win = 0;
}

void place_o(char **tab, char **clone_tab, int i, int j)
{
    if (clone_tab[i][j] == 'O' && tab[i][j] == ' ')
        tab[i][j] = 'O';
}

void add_count(char **tab, char **clone_tab, buffer_t *tmp, int i)
{
    for (int j = 0; tab[i][j] != '\n'; j++) {
        if (clone_tab[i][j] == 'O' && tab[i][j] == 'X')
            tmp->count_win++;
    }
}

void win_cond(buffer_t *tmp, char **tab)
{
    int lines = nb_line(tmp);
    int cols = count_char(tmp);

    for (int j = 0; tab[j] != NULL; j++) {
        mvprintw(LINES / 2 - (lines / 2 - j), COLS / 2 - cols / 2,
        (my_strcat(tab[j], "\n")));
    }
    if (tmp->count == tmp->count_win) {
        print_tab_first(tab, lines, cols);
        endwin();
        my_putstr("You won !\n");
        exit(0);
    }
}
