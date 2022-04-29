# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksaffron <ksaffron@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/04 17:10:08 by ksaffron          #+#    #+#              #
#    Updated: 2022/04/29 16:38:36 by ksaffron         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
FLAGS = -Wall -Wextra -Werror #-g -fsanitize=address
CC = gcc

HEADER = so_long.h

SOURCE =	so_long.c ft_error.c ft_read_map.c \
			correctmap.c map_size.c

OBJECTS = $(SOURCE:.c=.o)
LIBFT_SOURCE = ./libft/
LIBFT = libft.a

RM = rm -f

all: $(NAME)

%.o : %.c $(HEADER) Makefile
	$(CC) $(FLAGS) -I. -I$(LIBFT_SOURCE) -Imlx -c $< -o $@

$(NAME): $(OBJECTS) $(HEADER) $(LIBFT_SOURCE)$(LIBFT) Makefile
	$(CC) $(FLAGS) $(OBJECTS) $(LIBFT_SOURCE)$(LIBFT) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(LIBFT_SOURCE)$(LIBFT): libft ;

libft:
	make bonus -C $(LIBFT_SOURCE)

clean:
	$(RM) $(OBJECTS)
	make clean -C $(LIBFT_SOURCE)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_SOURCE)

re: fclean all

.PHONY: all clean fclean re libft
