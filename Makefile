# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksaffron <ksaffron@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/04 17:10:08 by ksaffron          #+#    #+#              #
#    Updated: 2022/02/04 18:20:53 by ksaffron         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

#LIBFT = ./libft/libft.a

FLAGS = -Wall -Wextra -Werror

SRC = so_long.c

OBJ = $(patsubst %.c, %.o, $(SRC))

HEADER = so_long.h

RM = rm -f

all:	$(NAME)

$(NAME):	$(HEADER) $(OBJ)
	cc $(FLAGS) $(OBJ) -Lminilibx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	cc $(FLAGS) -Imlx -c $< -o $@ -I $(HEADER)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re: clean fclean all

.PHONY: all clean fclean re
