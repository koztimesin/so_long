/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaffron <ksaffron@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:28:47 by ksaffron          #+#    #+#             */
/*   Updated: 2022/05/25 19:28:43 by ksaffron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

// static void	ft_print_move_bonus(t_game_b *game)
// {
// 	game->moves++;
// 	ft_putnbr_fd(game->moves, 1);
// 	ft_putchar_fd('\n', 1);
// }

int	ft_move_bonus(int key, t_game_b *game)
{
	if (key == ESC)
		ft_close_game_bonus(game);
	if (key == W)
		ft_move_player_w(game, 0, -1);
	if (key == S)
		ft_move_player_s(game, 0, 1);
	if (key == A)
		ft_move_player_a(game, -1, 0);
	if (key == D)
		ft_move_player_d(game, 1, 0);
	return (0);
}
