/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaffron <ksaffron@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:14:43 by ksaffron          #+#    #+#             */
/*   Updated: 2022/05/07 16:25:39 by ksaffron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

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
	ft_draw_img(&game);
	mlx_loop(game.mlx);
}
