/*
** EPITECH PROJECT, 2022
** my_sokoban
** File description:
** Sokoban Project 2022
*/

#include "include/my.h"

int nb_line_c(buffer_t *tmp)
{
    int nbl = 0;

    for (int i = 0; tmp->buffer[i] != '\0'; i++) {
        if (tmp->buffer[i] == '\n') {
            nbl++;
        }
    }
    return (nbl);
}

int count_char_c (buffer_t *tmp)
{
    int cnchar = 0;

    for (int i = 0; tmp->buffer[i] != '\n'; i++) {
        cnchar++;
        if (tmp->buffer[i + 1] == '\n')
            cnchar += 1;
    }
    return (cnchar);
}

char **malloc_tab_c(buffer_t *tmp)
{
    char **tab;
    int i = 0;

    tab = malloc(sizeof(char *) * (nb_line_c(tmp) + 1));
    while (i < nb_line_c(tmp)) {
        tab[i] = malloc(sizeof(char) * (count_char_c(tmp) + 1));
        i++;
    }
    fill_tab_c(tab, tmp);
    return tab;
}

void fill_tab_c(char **tab, buffer_t *tmp)
{
    int i = 0;

    for (; tmp->buffer[i] != '\0'; tmp->g++, i++) {
        for (tmp->h = 0; tmp->buffer[i] != '\n'; tmp->h++, i++) {
            tab[tmp->g][tmp->h] = tmp->buffer[i];
            fill_rest_tab_c(tmp, i, tab);
        }
    }
    tab[nb_line_c(tmp)] = NULL;
}

void fill_rest_tab_c(buffer_t *tmp, int i, char **tab)
{
    if (tmp->buffer[i + 1] == '\n') {
        tab[tmp->g][tmp->h + 1] = '\n';
        tab[tmp->g][tmp->h + 2] = '\0';
    }
}
