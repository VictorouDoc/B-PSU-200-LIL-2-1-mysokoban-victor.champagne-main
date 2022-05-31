/*
** EPITECH PROJECT, 2022
** my_sokoban
** File description:
** Sokoban Project 2022
*/

#include "my.h"

#ifndef _STRUCT_H_
    #define _STRUCT_H_

typedef struct buffer {
    int bytes;
    char *buffer;
    int fd;
    int size;
    int x;
    int y;
    int keyenter;
    int i;
    int j;
    int g;
    int h;
    int count;
    int count_win;
    int xa;
    int yb;
    int count_x;
    int count_sx;
    int count_p;
    int stock_i;
    int stock_j;
} buffer_t;

#endif
