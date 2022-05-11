/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaffron <ksaffron@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 18:58:23 by ksaffron          #+#    #+#             */
/*   Updated: 2022/05/05 19:03:36 by ksaffron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_get_into(t_game *game)
{
	int	x;
	int	y;
	int	c;

	y = 0;
	c = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				game->px = x;
				game->py = y;
			}
			if (game->map[y][x] == 'C')
				c++;
			x++;
		}
		y++;
	}
	game->coins = c;
}