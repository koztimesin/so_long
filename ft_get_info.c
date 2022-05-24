/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaffron <ksaffron@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 18:58:23 by ksaffron          #+#    #+#             */
/*   Updated: 2022/05/24 14:46:10 by ksaffron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_size(t_game *game)
{
	int	x = 0, y = 0;

	while (game->map[y][x])
		x++;
	while (game->map[y])
		y++;
	game->height = y;
	game->length = x;
}

void	ft_get_into(t_game *game)
{
	int	x;
	int	y;
	int	c;

	y = 0;
	c = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->length)
		{
			if (game->map[y][x] == 'P')
			{
				game->px = x;
				game->py = y;
			}
			if (game->map[y][x] == 'E')
			{
				game->ex = x;
				game->ey = y;
			}
			if (game->map[y][x] == 'C')
				c++;
			x++;
		}
		y++;
	}
	game->coins = c;
}
