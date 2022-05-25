/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_info_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaffron <ksaffron@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 19:30:52 by ksaffron          #+#    #+#             */
/*   Updated: 2022/05/25 19:33:34 by ksaffron         ###   ########.fr       */
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
	if (x > 40 || y > 21)
		ft_error(game->map);
	game->height = y;
	game->length = x;
}

static void	ft_get_info_cycle_bonus(t_game_b *game, int *c)
{
	int	x;
	int	y;
	int	p;

	p = 0;
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
			if (game->map[y][x] == 'P')
				p++;
			if (game->map[y][x] == 'C')
				*c += 1;
		}
	}
	if (p != 1)
		ft_close_game_bonus(game);
}

void	ft_get_info_bonus(t_game_b *game)
{
	int	c;

	c = 0;
	ft_map_size_bonus(game);
	ft_get_info_cycle_bonus(game, &c);
	game->coins = c;
}
