##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRC	=	src/password_generator.c

OBJ	=	$(SRC:.c=.o)

GTK	=	$(shell pkg-config --cflags --libs gtk+-3.0)

NAME	=	password_generator

all:	$(NAME)

$(NAME):	$(SRC)
	gcc -o $(NAME) $(SRC) $(GTK)

clean:
	rm -f	$(OBJ)
	rm -f *~
	rm -f *.o

fclean:	clean
	rm -f $(NAME)

re:	fclean all
