/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaffron <ksaffron@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:14:43 by ksaffron          #+#    #+#             */
/*   Updated: 2022/05/11 18:23:43 by ksaffron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

static int	close_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	exit(0);
}

static int	render_next_frame(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->length)
		{
			if (game->map[y][x] == 'C')
			{
				ft_draw_map(game, GROUND, x * 64, y * 64);
				ft_draw_map(game, TREAT, x * 64, y * 64);
			}
			x++;
		}
		y++;
	}
	ft_draw_map(game, PLAYER, game->px * 64, (game->py - 1) * 64);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		ft_error();
	ft_check_name(argv[1]);
	ft_read_map(&game, argv[1]);
	ft_correctmap(game.map);
	map_size(&game);
	ft_get_into(&game);
	ft_game_init(&game);
	mlx_hook(game.window, 2, 0, &ft_move, &game);
	mlx_hook(game.window, 17, 0, &close_game, &game);
	ft_draw_img(&game);
	mlx_loop_hook(game.mlx, &render_next_frame, &game);
	mlx_loop(game.mlx);
}
