/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_info_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaffron <ksaffron@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 19:30:52 by ksaffron          #+#    #+#             */
/*   Updated: 2022/05/27 15:52:38 by ksaffron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	ft_map_size_bonus(t_game_b *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map[y][x])
		x++;
	while (game->map[y])
		y++;
	game->height = y;
	game->length = x;
}

static void	ft_count(t_game *game)
{
	int	x;
	int	y;
	int	e;
	int	p;

	e = 0;
	p = 0;
	y = -1;
	while (++y < game->height)
	{
		x = -1;
		while (++x < game->length)
		{
			if (game->map[y][x] == 'E')
				e++;
			if (game->map[y][x] == 'P')
				p++;
		}
	}
	if (p != 1 || e < 1)
		ft_error(game->map);
}

static void	ft_get_info_cycle_bonus(t_game_b *game, int *c)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->height)
	{
		x = -1;
		while (++x < game->length)
		{
			if (game->map[y][x] == 'P')
				game->px = x;
			if (game->map[y][x] == 'P')
				game->py = y;
			if (game->map[y][x] == 'C')
				*c += 1;
		}
	}
	if (*c < 1)
		ft_error(game->map);
}

void	ft_get_info_bonus(t_game_b *game)
{
	int	c;

	c = 0;
	ft_map_size_bonus(game);
	ft_get_info_cycle_bonus(game, &c);
	game->coins = c;
}
