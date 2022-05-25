/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaffron <ksaffron@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:04:39 by ksaffron          #+#    #+#             */
/*   Updated: 2022/05/25 19:35:29 by ksaffron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# define ENEMY "./assets/enemy.xpm"
# define ENEMY_W "./assets/enemy_w.xpm"
# define ENEMY_D "./assets/enemy_d.xpm"
# define ENEMY_A "./assets/enemy_a.xpm"
# define PLAYER_W "./assets/player_w.xpm"
# define PLAYER_D "./assets/player_d.xpm"
# define PLAYER_A "./assets/player_a.xpm"
# define BOX "./assets/box.xpm"

# define OPEN 1
# define CLOSE 0

# include "so_long.h"

typedef struct s_game_b {
	char	**map;
	void	*mlx;
	void	*window;
	int		height;
	int		length;
	int		px;
	int		py;
	int		coins;
	int		score;
	int		status;
	int		moves;
}				t_game_b;

void	ft_game_init_bonus(t_game_b *game);
int		ft_move_bonus(int key, t_game_b *game);
void	ft_get_info_bonus(t_game_b *game);
int		ft_draw_img_bonus(t_game_b *game);
int		ft_next_frame(t_game_b *game);
void	ft_read_map_bonus(t_game_b *game, char *file);
void	ft_move_player_w(t_game_b *game, int x, int y);
void	ft_move_player_s(t_game_b *game, int x, int y);
void	ft_move_player_a(t_game_b *game, int x, int y);
void	ft_move_player_d(t_game_b *game, int x, int y);
int		ft_close_game_bonus(t_game_b *game);
void	ft_draw_map_bonus(t_game_b *game, char *asset, int x, int y);

#endif
