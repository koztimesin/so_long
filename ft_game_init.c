/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaffron <ksaffron@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:58:54 by ksaffron          #+#    #+#             */
/*   Updated: 2022/05/27 16:21:46 by ksaffron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	ft_game_init(t_game *game)
{
	int	x;
	int	y;
	ft_correct_map(game->map);
	ft_get_info(game);
	ft_wrapped_map(game);
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_game_error(game);
	game->window = mlx_new_window(game->mlx, game->length * 64, \
	game->height * 64, "so_long");
	if (!game->window)
		ft_game_error(game);
	mlx_get_screen_size(game->mlx, &x, &y);
	if ((x / 64) > 40 || (y / 64) > 21)
		ft_game_error(game);
	ft_draw_map(game);
}
