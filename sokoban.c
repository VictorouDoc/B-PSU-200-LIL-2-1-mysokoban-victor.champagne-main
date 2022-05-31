/*
** EPITECH PROJECT, 2022
** my_sokoban
** File description:
** Sokoban Project 2022
*/

#include "include/my.h"

void big_fct(char **clone_tab, char **tab, buffer_t *tmp)
{
    restart_map(tab, clone_tab, tmp);
    input_up(tab, tmp);
    input_right(tab, tmp);
    input_down(tab, tmp);
    input_left(tab, tmp);
    for (int i = 0; tab[i] != NULL; i++) {
        add_count(tab, clone_tab, tmp, i);
    }
    foro(clone_tab, tab, tmp);
}

int sokoban(buffer_t *tmp)
{
    char **tab = malloc_tab(tmp);
    char **clone_tab = malloc_tab_c(tmp);
    int lines = nb_line(tmp);
    int cols = count_char(tmp);

    set_ncurse(tab, tmp);
    print_tab_first(tab, lines, cols);
    while (tmp->keyenter != 113) {
        too_small_win(lines, cols);
        tmp->keyenter = getch();
        big_fct(clone_tab, tab, tmp);
        for (int i = 0; tab[i] != NULL; i++) {
            lose_check(tab, clone_tab, tmp, i);
        }
        clear();
        print_tab_first(tab, lines, cols);
        refresh();
    }
    endwin();
    return 0;
}

buffer_t *map(char *filepath)
{
    struct stat sb;
    buffer_t *tmp = malloc(sizeof(buffer_t));
    tmp->fd = open(filepath, O_RDONLY);
    stat(filepath, &sb);
    tmp->bytes = sb.st_size;
    tmp->buffer = malloc(sizeof(char) * (tmp->bytes + 1));

    if (stat(filepath, &sb) == -1) {
        return (tmp);
    }
    set_to_zero(tmp);
    tmp->size = read(tmp->fd, tmp->buffer, tmp->bytes);
    tmp->buffer[tmp->bytes] = '\0';
    return (tmp);
}

int main(int ac, char **av)
{
    buffer_t *tmp = map(av[1]);

    if (ac != 2) {
        my_putstr("Must Contain a map.\n");
        return (84);
    }
    if (ac == 2 && (av[1][0] == '-' || av[1][1] == 'h')) {
        usage_fct();
        return 1;
    }
    sokoban(tmp);
}

void usage_fct(void)
{
    my_putstr("USAGE\n\t./my_sokoban map\nDESCRIPTION\n");
    my_putstr("\tMap file representing the warehouse map, containing");
    my_putstr(" '#' for walls,\n\t'P' for the player, 'X' for boxes");
    my_putstr(" and '0' for storage locations.\n");
    my_putstr("GAME\n\tPress Q for leave the game\nSpace bar for replay");
}
