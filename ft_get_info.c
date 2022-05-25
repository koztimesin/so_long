/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaffron <ksaffron@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 18:58:23 by ksaffron          #+#    #+#             */
/*   Updated: 2022/05/25 16:02:19 by ksaffron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_size(t_game *game)
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
	if (p != 1 || e != 1)
		ft_error(game->map);
}

static void	ft_get_info_cycle(t_game *game, int *c)
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
			if (game->map[y][x] == 'E')
				game->ex = x;
			if (game->map[y][x] == 'E')
				game->ey = y;
			if (game->map[y][x] == 'C')
				*c += 1;
		}
	}
}

void	ft_get_info(t_game *game)
{
	int	c;

	c = 0;
	ft_map_size(game);
	ft_count(game);
	ft_get_info_cycle(game, &c);
	game->coins = c;
}
