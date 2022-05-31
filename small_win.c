/*
** EPITECH PROJECT, 2022
** my_sokoban
** File description:
** Sokoban Project 2022
*/

#include "include/my.h"

void too_small_win(int lines, int cols)
{
    if (COLS < lines + 40 || LINES < cols - 14) {
        clear();
        mvprintw(LINES / 2, COLS / 2 - 6, "Window to small");
        refresh();
    }
}
