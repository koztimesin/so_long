/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_init_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaffron <ksaffron@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:55:59 by ksaffron          #+#    #+#             */
/*   Updated: 2022/05/25 19:34:35 by ksaffron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	ft_wrapped_map_bonus(t_game_b *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map[0][x])
	{
		if (game->map[0][x] != '1' || game->map[game->height - 1][x] != '1')
			ft_error(game->map);
		x++;
	}
	while (game->map[y])
	{
		if (game->map[y][0] != '1' || game->map[y][game->length - 1] != '1')
			ft_error(game->map);
		y++;
	}
}


int	ft_close_game_bonus(t_game_b *game)
{
	mlx_destroy_window(game->mlx, game->window);
	ft_free_space(game->map);
	exit(0);
}

static void	ft_correct_map_bonus(char **map)
{
	int	x;
	int	y;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
			if (map[y][x] != '1' && map[y][x] != '0' && map[y][x] != 'E'
			&& map[y][x] != 'C' && map[y][x] != 'P' && map[y][x] != 'B')
				ft_error(map);
	}
}

void	ft_game_init_bonus(t_game_b *game)
{
	ft_correct_map_bonus(game->map);
	ft_get_info_bonus(game);
	ft_wrapped_map_bonus(game);
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, game->length * 64, \
	game->height * 64, "so_long_bonus");
	ft_draw_img_bonus(game);
}
