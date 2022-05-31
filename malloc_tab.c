/*
** EPITECH PROJECT, 2022
** my_sokoban
** File description:
** Sokoban Project 2022
*/

#include "include/my.h"

int nb_line(buffer_t *tmp)
{
    int nbl = 0;

    for (int i = 0; tmp->buffer[i] != '\0'; i++) {
        if (tmp->buffer[i] == '\n') {
            nbl++;
        }
    }
    return (nbl);
}

int count_char (buffer_t *tmp)
{
    int cnchar = 0;

    for (int i = 0; tmp->buffer[i] != '\n'; i++) {
        cnchar++;
        if (tmp->buffer[i + 1] == '\n')
            cnchar += 1;
    }
    return (cnchar);
}

char **malloc_tab(buffer_t *tmp)
{
    char **tab;
    int i = 0;

    tab = malloc(sizeof(char *) * (nb_line(tmp) + 1));
    while (i < nb_line(tmp)) {
        tab[i] = malloc(sizeof(char) * (count_char(tmp) + 1));
        i++;
    }
    fill_tab(tab, tmp);
    return tab;
}

void fill_tab(char **tab, buffer_t *tmp)
{
    int i = 0;

    for (; tmp->buffer[i] != '\0'; tmp->x++, i++) {
        for (tmp->y = 0; tmp->buffer[i] != '\n'; tmp->y++, i++) {
            tab[tmp->x][tmp->y] = tmp->buffer[i];
            fill_rest_tab(tmp, i, tab);
        }
    }
    tab[nb_line(tmp)] = NULL;
}

void fill_rest_tab(buffer_t *tmp, int i, char **tab)
{
    if (tmp->buffer[i + 1] == '\n') {
        tab[tmp->x][tmp->y + 1] = '\n';
        tab[tmp->x][tmp->y + 2] = '\0';
    }
}
