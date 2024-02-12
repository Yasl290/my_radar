##
## EPITECH PROJECT, 2023
## LIB
## File description:
## Makefile
##

SRC =	funct_mini_printf.c	\
		get_flags.c	\
		my_atoi.c	\
		my_compute_power_rec.c	\
		my_digit.c	\
		my_printf.c	\
		my_put_nbr.c	\
		my_putchar.c	\
		my_putstr.c	\
		my_revstr.c	\
		my_strcmp.c	\
		my_strcpy.c	\
		my_strlen.c	\
		my_strlowcase.c	\
		my_strncpy.c	\
		my_strupcase.c	\
		my_swap.c	\
		my_unsigned_nbr.c	\
		my_unsigned_o.c	\
		my_unsigned_upperx.c	\
		my_unsigned_x.c	\
		padding_char.c	\
		padding.c	\
		print_f.c	\
		print_upperf.c	\
		printf_flags.c	\
		unsigned_flags.c	\
		env_check.c	\
		opening.c	\
		radar_window.c	\
		radar_clean.c	\
		radar_init.c	\
		radar_sound.c	\
		radar_wind.c	\
		radar_parsing.c	\
		radar_aircraft.c	\
		radar_condition.c	\
		check_path.c	\
		radar_values.c	\
		radar_parse_line.c	\
		radar_script_path.c	\
		radar_tower.c	\
		radar_aircrafts.c	\
		radar_initialize.c	\
		radar_display.c	\
		radar_moves.c	\
		radar_timer.c	\
		radar_events.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

CFLAGS	+=	-Wall	-Wextra	-I	include/	-Llib/my	-lmy

all	:	$(NAME)

$(NAME):	$(OBJ)
	@echo	"start"
	ar rc libmy.a $(OBJ)
	@echo "end"

clean:
	rm $(OBJ)

fclean:
	rm libmy.a

re:	fclean	$(NAME)
