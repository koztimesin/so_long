# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksaffron <ksaffron@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/04 17:10:08 by ksaffron          #+#    #+#              #
#    Updated: 2022/05/26 18:10:29 by ksaffron         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_B = so_long_bonus
FLAGS = -Wall -Wextra -Werror -g -fsanitize=address
CC = gcc

HEADER = so_long.h so_long_bonus.h

SOURCE =	so_long.c ft_error.c ft_read_map.c \
			ft_correct_map.c ft_get_info.c ft_game_init.c \
			ft_draw_map.c ft_move.c \

SOURCE_B =	so_long_bonus.c ft_move_bonus.c ft_get_info_bonus.c \
			ft_game_init_bonus.c ft_draw_map_bonus.c ft_error.c \
			ft_read_map_bonus.c ft_correct_map.c

OBJECTS = $(SOURCE:.c=.o)
OBJECTS_B = $(SOURCE_B:.c=.o)
LIBFT_SOURCE = ./libft/
LIBFT = libft.a

RM = rm -f

all: $(NAME)

%.o : %.c $(HEADER) Makefile
	$(CC) $(FLAGS) -I. -I$(LIBFT_SOURCE) -Imlx -c $< -o $@

$(NAME): $(OBJECTS) $(HEADER) $(LIBFT_SOURCE)$(LIBFT) libmlx.dylib Makefile
	$(CC) $(FLAGS) $(OBJECTS) $(LIBFT_SOURCE)$(LIBFT) -lmlx -framework OpenGL -framework AppKit libmlx.dylib -o $(NAME)

$(NAME_B): $(OBJECTS_B) $(HEADER) $(LIBFT_SOURCE)$(LIBFT) libmlx.dylib Makefile
	$(CC) $(FLAGS) $(OBJECTS_B) $(LIBFT_SOURCE)$(LIBFT) -lmlx -framework OpenGL -framework AppKit libmlx.dylib -o $(NAME_B)

$(LIBFT_SOURCE)$(LIBFT): libft ;

libmlx.dylib:
	cd minilibx && make && mv libmlx.dylib ../

bonus: $(NAME_B)

libft:
	make bonus -C $(LIBFT_SOURCE)

clean:
	$(RM) $(OBJECTS)
	$(RM) $(OBJECTS_B)
	make clean -C $(LIBFT_SOURCE)
	make clean -C ./minilibx/ clean
	rm -f libmlx.dylib

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME_B)
	make fclean -C $(LIBFT_SOURCE)

re: fclean all

.PHONY: all clean fclean re libft bonus
