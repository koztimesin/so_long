/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaffron <ksaffron@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:00:36 by ksaffron          #+#    #+#             */
/*   Updated: 2022/05/05 16:02:14 by ksaffron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# define W 13
# define S 1
# define A 0
# define D 2
# define ESC 53

# define KEYEXIT 17

# define WALL "./assets/tile01.xpm"
# define GROUND "./assets/tile00.xpm"
# define TREAT "./assets/ball.xpm"
# define PLAYER "./assets/player_S00.xpm"
# define EXIT "./assets/ladder.xpm"

# include "./minilibx/mlx.h"
# include "./libft/libft.h"
# include <fcntl.h>

typedef struct s_game {
	char			**map;
	void			*mlx;
	void			*window;
	unsigned int	height;
	unsigned int	length;
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
void	map_size(t_game *game);
void	ft_game_init(t_game *game);

#endif
