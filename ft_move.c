/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaffron <ksaffron@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:30:43 by ksaffron          #+#    #+#             */
/*   Updated: 2022/05/26 18:07:13 by ksaffron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_print_move(t_game *game)
{
	game->moves++;
	ft_putnbr_fd(game->moves, 1);
	ft_putchar_fd('\n', 1);
}

static void	ft_move_player(t_game *game, int x, int y)
{
	if (game->map[game->py + y][game->px + x] == '1')
		return ;
	if (game->map[game->py + y][game->px + x] == 'C')
	{
		game->map[game->py + y][game->px + x] = '0';
		game->score++;
	}
	if (game->score == game->coins)
		ft_draw_img(game, EXIT, game->ex * 64, game->ey * 64);
	if (game->map[game->py + y][game->px + x] == 'E')
	{
		if (game->score == game->coins)
			ft_close_game(game);
		else
			return ;
	}
	ft_print_move(game);
	ft_draw_img(game, GROUND, game->px * 64, game->py * 64);
	game->px = game->px + x;
	game->py = game->py + y;
	ft_draw_img(game, PLAYER, game->px * 64, game->py * 64);
}

int	ft_move(int key, t_game *game)
{
	if (key == ESC)
		ft_close_game(game);
	if (key == W)
		ft_move_player(game, 0, -1);
	if (key == S)
		ft_move_player(game, 0, 1);
	if (key == A)
		ft_move_player(game, -1, 0);
	if (key == D)
		ft_move_player(game, 1, 0);
	return (0);
}
