/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_correctmap2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaffron <ksaffron@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:27:21 by ksaffron          #+#    #+#             */
/*   Updated: 2022/05/12 16:36:31 by ksaffron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_wrapped_map(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while(game->map[0][x])
	{
		if (game->map[0][x] != '1' || game->map[game->height - 1][x] != '1')
			ft_error();
		x++;
	}
	while (game->map[y])
	{
		if (game->map[y][0] != '1' || game->map[y][game->length - 1] != '1')
			ft_error();
		y++;
	}
}
