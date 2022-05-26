/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaffron <ksaffron@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:04:37 by ksaffron          #+#    #+#             */
/*   Updated: 2022/05/26 17:49:00 by ksaffron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_game_b	game;

	if (argc != 2)
		ft_error(NULL);
	ft_check_name(argv[1]);
	ft_read_map_bonus(&game, argv[1]);
	ft_game_init_bonus(&game);
	mlx_hook(game.window, 2, 1L << 0, &ft_move_bonus, &game);
	mlx_hook(game.window, 17, 1L << 0, &ft_close_game, &game);
	mlx_loop_hook(game.mlx, &ft_next_frame, &game);
	mlx_loop(game.mlx);
}
