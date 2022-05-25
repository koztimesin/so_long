/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_direction_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaffron <ksaffron@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 19:07:57 by ksaffron          #+#    #+#             */
/*   Updated: 2022/05/25 19:40:58 by ksaffron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_move_player_w(t_game_b *game, int x, int y)
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
	// ft_print_move(game);
	ft_draw_map_bonus(game, GROUND, game->px * 64, game->py * 64);
	game->px = game->px + x;
	game->py = game->py + y;
	ft_draw_map_bonus(game, PLAYER_W, game->px * 64, game->py * 64);
}

void	ft_move_player_s(t_game_b *game, int x, int y)
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
	// ft_print_move(game);
	ft_draw_map_bonus(game, GROUND, game->px * 64, game->py * 64);
	game->px = game->px + x;
	game->py = game->py + y;
	ft_draw_map_bonus(game, PLAYER, game->px * 64, game->py * 64);
}

void	ft_move_player_a(t_game_b *game, int x, int y)
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
	// ft_print_move(game);
	ft_draw_map_bonus(game, GROUND, game->px * 64, game->py * 64);
	game->px = game->px + x;
	game->py = game->py + y;
	ft_draw_map_bonus(game, PLAYER_A, game->px * 64, game->py * 64);
}

void	ft_move_player_d(t_game_b *game, int x, int y)
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
	// ft_print_move_(game);
	ft_draw_map_bonus(game, GROUND, game->px * 64, game->py * 64);
	game->px = game->px + x;
	game->py = game->py + y;
	ft_draw_map_bonus(game, PLAYER_D, game->px * 64, game->py * 64);
}
