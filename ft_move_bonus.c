/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaffron <ksaffron@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:28:47 by ksaffron          #+#    #+#             */
/*   Updated: 2022/05/26 18:07:00 by ksaffron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	ft_move_player_bonus(t_game_b *game, int x, int y)
{
	if (game->map[game->py + y][game->px + x] == '1')
		return ;
	if (game->map[game->py + y][game->px + x] == 'B')
		ft_close_game_bonus(game);
	if (game->map[game->py + y][game->px + x] == 'C')
	{
		game->map[game->py + y][game->px + x] = '0';
		game->score++;
	}
	if (game->score == game->coins)
		game->status = OPEN;
	if (game->map[game->py + y][game->px + x] == 'E')
	{
		if (game->score == game->coins)
			ft_close_game_bonus(game);
		else
			return ;
	}
	game->moves++;
	ft_draw_img_bonus(game, GROUND, game->px * 64, game->py * 64);
	game->px = game->px + x;
	game->py = game->py + y;
	ft_draw_img_bonus(game, game->img, game->px * 64, game->py * 64);
}

int	ft_move_bonus(int key, t_game_b *game)
{
	if (key == ESC)
		ft_close_game_bonus(game);
	if (key == W)
	{
		game->img = PLAYER_W;
		ft_move_player_bonus(game, 0, -1);
	}
	if (key == S)
	{
		game->img = PLAYER;
		ft_move_player_bonus(game, 0, 1);
	}
	if (key == A)
	{
		game->img = PLAYER_A;
		ft_move_player_bonus(game, -1, 0);
	}
	if (key == D)
	{
		game->img = PLAYER_D;
		ft_move_player_bonus(game, 1, 0);
	}
	return (0);
}
