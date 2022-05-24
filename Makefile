# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksaffron <ksaffron@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/04 17:10:08 by ksaffron          #+#    #+#              #
#    Updated: 2022/05/24 21:07:28 by ksaffron         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
FLAGS = -Wall -Wextra -Werror -g -fsanitize=address
CC = gcc

HEADER = so_long.h

SOURCE =	so_long.c ft_error.c ft_read_map.c \
			ft_correct_map.c ft_get_info.c ft_game_init.c \
			ft_draw_map.c ft_move.c \

OBJECTS = $(SOURCE:.c=.o)
LIBFT_SOURCE = ./libft/
LIBFT = libft.a

RM = rm -f

all: $(NAME)

%.o : %.c $(HEADER) Makefile
	$(CC) $(FLAGS) -I. -I$(LIBFT_SOURCE) -Imlx -c $< -o $@

$(NAME): $(OBJECTS) $(HEADER) $(LIBFT_SOURCE)$(LIBFT) libmlx.dylib Makefile
	$(CC) $(FLAGS) $(OBJECTS) $(LIBFT_SOURCE)$(LIBFT) -lmlx -framework OpenGL -framework AppKit libmlx.dylib -o $(NAME)

$(LIBFT_SOURCE)$(LIBFT): libft ;

libmlx.dylib:
	cd minilibx && make && mv libmlx.dylib ../

libft:
	make bonus -C $(LIBFT_SOURCE)

clean:
	$(RM) $(OBJECTS)
	make clean -C $(LIBFT_SOURCE)
	make clean -C ./minilibx/ clean
	rm -f libmlx.dylib

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_SOURCE)

re: fclean all

.PHONY: all clean fclean re libft
