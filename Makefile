##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## makethefile for my_radar
##

NAME	=	my_radar

all:	$(NAME)

$(NAME):
	@echo "start program"
	make -C lib/my
	gcc -o $(NAME) radar.c -Llib/my -lmy -lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window -lm
	@echo "end program"

clean:
	make -C lib/my clean
	rm -f ./lib/my/libmy.a

fclean: clean
	rm -f $(NAME)
	make -C lib/my fclean

re: fclean all
