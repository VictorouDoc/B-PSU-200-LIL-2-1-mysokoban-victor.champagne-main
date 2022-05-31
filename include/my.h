/*
** EPITECH PROJECT, 2022
** my_sokoban
** File description:
** Sokoban Project 2022
*/

#ifndef MY_
    #define MY_

    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <stdio.h>
    #include <string.h>
    #include <sys/wait.h>
    #include "struct.h"
    #include <ncurses.h>
    #include <fcntl.h>
    #include <curses.h>

    void my_putchar(char c);

    char *my_putstr(char const *str);

    void usage_fct(void);

    buffer_t *map(char *filepath);

    int my_strlen(char const *str);

    int sokoban(buffer_t *tmp);

    int count_char (buffer_t *tmp);

    char **malloc_tab(buffer_t *tmp);

    int nb_line(buffer_t *tmp);

    void fill_rest_tab(buffer_t *tmp, int i, char **tab);

    void fill_tab(char **tab, buffer_t *tmp);

    void print_tab(char **tabl);

    char *my_strcat(char *dest, char *src);

    void input_up(char **tab, buffer_t *tmp);

    void input_up(char **tab, buffer_t *tmp);

    void no_x_up(char **tab, buffer_t *tmp);

    void big_fct(char **clone_tab, char **tab, buffer_t *tmp);

    void get_pos(char **tab, buffer_t *tmp);

    void no_x_down(char **tab, buffer_t *tmp);

    void input_down(char **tab, buffer_t *tmp);

    void input_left(char **tab, buffer_t *tmp);

    void no_x_left(char **tab, buffer_t *tmp);

    void input_right(char **tab, buffer_t *tmp);

    void no_x_right(char **tab, buffer_t *tmp);

    void foro(char **clone_tab, char **tab, buffer_t *tmp);

    int nb_line_c(buffer_t *tmp);

    int count_char_c (buffer_t *tmp);

    char **malloc_tab_c(buffer_t *tmp);

    void fill_tab_c(char **tab, buffer_t *tmp);

    void fill_rest_tab_c(buffer_t *tmp, int i, char **tab);

    int scan_map_victory(char **tab, buffer_t *tmp);

    void place_o(char **tab, char **clone_tab, int i, int j);

    void win(buffer_t *tmp);

    void lose_check(char **tab, char **clone_tab, buffer_t *tmp, int i);

    void win_cond(buffer_t *tmp, char **tab);

    void add_count(char **tab, char **clone_tab, buffer_t *tmp, int i);

    void stock_pos(char **tab, buffer_t *tmp, int i , int j);

    void set_ncurse (char **tab, buffer_t *tmp);

    void print_tab_first (char **tab, int lines, int cols);

    void set_to_zero(buffer_t *tmp);

    void put_o(char **tab, buffer_t *tmp, int i, int j);

    void cond_end(buffer_t *tmp);

    void check_p(buffer_t *tmp);

    void restart_map(char **tab, char **clone_tab, buffer_t *tmp);

    char *my_strcpy(char *dest, char const *src);

    void reset_to_zero(buffer_t *tmp);

    void too_small_win(int lines, int cols);

    void check_o_count(buffer_t *tmp);
#endif
