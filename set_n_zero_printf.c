/*
** EPITECH PROJECT, 2022
** my_sokoban
** File description:
** Sokoban Project 2022
*/

#include "include/my.h"

void set_ncurse (char **tab, buffer_t *tmp)
{
    check_o_count(tmp);
    check_p(tmp);
    initscr();
    curs_set(false);
    keypad(stdscr, TRUE);
    get_pos(tab, tmp);
    scan_map_victory(tab, tmp);
}

void print_tab_first (char **tab, int lines, int cols)
{
    for (int j = 0; tab[j] != NULL; j++) {
        mvprintw(LINES / 2 - (lines / 2 - j), COLS / 2 - cols / 2,
        (my_strcat(tab[j], "\n")));
    }
}

void set_to_zero(buffer_t *tmp)
{
    tmp->keyenter = 0;
    tmp->count_p = 0;
    tmp->x = 0;
    tmp->y = 0;
    tmp->i = 0;
    tmp->j = 0;
    tmp->g = 0;
    tmp->h = 0;
    tmp->count = 0;
    tmp->count_win = 0;
    tmp->count_x = 0;
    tmp->count_sx = 0;
    tmp->stock_i = 0;
    tmp->stock_j = 0;
}

void check_p(buffer_t *tmp)
{
    int count_p = 0;
    for (int i = 0; tmp->buffer[i] != '\0'; i++) {
        if (tmp->buffer[i] == 'P')
            count_p++;
        if (tmp->buffer[i] != 'P' && tmp->buffer[i] != 'O'
        && tmp->buffer[i] != 'X' && tmp->buffer[i] != ' '
        && tmp->buffer[i] != '#' && tmp->buffer[i] != '\n') {
            my_putstr("Map Invalid\n");
            exit(84);
        }
    }
    if (count_p != 1) {
        my_putstr("Must Contain Only 1 'P'\n");
        exit(84);
    }
}

void check_o_count(buffer_t *tmp)
{
    int count_o = 0;
    int count_x = 0;

    for (int i = 0; tmp->buffer[i] != '\0'; i++) {
        if (tmp->buffer[i] == 'O')
            count_o++;
        if (tmp->buffer[i] == 'X')
            count_x++;
    }
    if (count_o > count_x) {
        my_putstr("Map Invalid : Too much 'O' or not enough 'X'\n");
        exit(84);
    }
}
