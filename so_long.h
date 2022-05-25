/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaffron <ksaffron@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:00:36 by ksaffron          #+#    #+#             */
/*   Updated: 2022/05/25 17:06:31 by ksaffron         ###   ########.fr       */
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
# define PLAYER "./assets/player.xpm"
# define EXIT "./assets/ladder.xpm"
# define STONE "./assets/stone.xpm"

# include "./minilibx/mlx.h"
# include "./libft/libft.h"
# include <fcntl.h>

typedef struct s_game {
	char	**map;
	void	*mlx;
	void	*window;
	int		height;
	int		length;
	int		px;
	int		py;
	int		coins;
	int		score;
	int		moves;
	int		ex;
	int		ey;
}				t_game;

void	ft_read_map(t_game *game, char *file);
void	ft_error(char **map);
void	ft_check_name(char *file);
void	ft_correct_map(char	**map);
void	ft_map_size(t_game *game);
void	ft_game_init(t_game *game);
void	ft_get_info(t_game *game);
void	ft_draw_map(t_game *game, char *asset, int x, int y);
int		ft_draw_img(t_game *game);
void	ft_move_player(t_game *game, int x, int y);
int		ft_move(int key, t_game *game);
void	ft_wrapped_map(t_game *game);
void	ft_check_length(char **map);
int		ft_close_game(t_game *game);

#endif
