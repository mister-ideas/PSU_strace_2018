##
## EPITECH PROJECT, 2019
## PSU_strace_2018
## File description:
## Makefile
##

CC=				gcc

SRC=			src/strace.c		\
			src/print.c

OBJ=			$(SRC:.c=.o)

NAME=			strace

CFLAGS=			-Wall -Wextra

CPPFLAGS	+=	-I./include

RM=				rm -f

all:			$(NAME)

$(NAME):		$(OBJ)
				$(CC) -o $(NAME) $(CFLAGS) $(OBJ)

clean:
				$(RM) $(OBJ)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
