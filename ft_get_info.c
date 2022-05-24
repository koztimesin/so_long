/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaffron <ksaffron@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 18:58:23 by ksaffron          #+#    #+#             */
/*   Updated: 2022/05/24 20:51:29 by ksaffron         ###   ########.fr       */
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
	game->height = y;
	game->length = x;
}

static void	ft_get_info_cycle(t_game *game, int *p, int *c)
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
			if (game->map[y][x] == 'P')
				*p += 1;
			if (game->map[y][x] == 'E')
				game->ex = x;
			if (game->map[y][x] == 'E')
				game->ey = y;
			if (game->map[y][x] == 'C')
				*c += 1;
		}
	}
	if (*p != 1)
		ft_error(game->map);
}

void	ft_get_info(t_game *game)
{
	int	c;
	int	p;

	c = 0;
	p = 0;
	ft_get_info_cycle(game, &p, &c);
	game->coins = c;
}
