##
## EPITECH PROJECT, 2025
## My_world
## File description:
## Makefile
##

NAME	=	my_world

CFLAGS	=	-I ./includes

SRC		=	src/main.c			\
			src/render_window.c	\
			src/find_iso.c	\
			src/save.c	\
			lib/shape.c	\
			lib/textures.c	\
			lib/sprites.c	\
			lib/events.c	\
			lib/musics.c	\
			lib/window.c	\
			lib/my_arrlen.c	\
			lib/free_array.c	\
			lib/action.c	\
			lib/my_strtok.c	\

OBJ		=	$(SRC:.c=.o)

CSFML	=	-lcsfml-window -lcsfml-system -lcsfml-graphics -lcsfml-audio -lm

all :	$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) $(CSFML) $(CFLAGS)

%.o	:	%.c
		gcc -c -o $@ $< $(CFLAGS) -g

run	:
		./$(NAME)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

debug:	CFLAGS+= -g
debug:	all

gdb:	debug
		gdb ./$(NAME)

valgrind:debug
		valgrind ./$(NAME)

perf:	fclean
perf:	CFLAGS+= -pg
perf:	all

re:	fclean all
