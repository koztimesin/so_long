/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaffron <ksaffron@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 16:04:42 by ksaffron          #+#    #+#             */
/*   Updated: 2022/05/07 16:30:01 by ksaffron         ###   ########.fr       */
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
