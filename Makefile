##
## EPITECH PROJECT, 2021
## Victor's Makefile
## File description:
## Make
##

SRC		=	sokoban.c	\
			stock_fct.c	\
			malloc_tab.c	\
			input.c	\
			get_pos.c	\
			input_side.c	\
			placeo_win.c	\
			malloc_tab_clone.c	\
			count_o.c	\
			lose.c	\
			set_n_zero_printf.c	\
			input_restart.c	\
			small_win.c	\


OBJ	=	$(SRC:.c=.o)

CC	=	gcc -g

NAME	=	my_sokoban

CFLAGS	= 	 -Iinclude -W -Wall -Wextra

all:	$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(CPPFLAGS) -lncurses

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
