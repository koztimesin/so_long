/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaffron <ksaffron@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:00:36 by ksaffron          #+#    #+#             */
/*   Updated: 2022/04/29 12:54:00 by ksaffron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include "./minilibx/mlx.h"
# include "./libft/libft.h"
# include <fcntl.h>

typedef struct s_game {
	char			**map;
	void			*mlx;
	void			*window;
	unsigned int	height;
	unsigned int	weight;
	unsigned int	px;
	unsigned int	py;
	unsigned int	coins;
	unsigned int	status;
	unsigned int	score;
	unsigned int	moves;
}				t_game;

void	ft_read_map(t_game *game, char *file);
void	ft_error(void);
void	ft_check_name(char *file);
void	ft_correctmap(char	**map);

#endif
