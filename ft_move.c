/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaffron <ksaffron@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:30:43 by ksaffron          #+#    #+#             */
/*   Updated: 2022/05/11 18:06:24 by ksaffron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_print_move(t_game *game)
{
	ft_putnbr_fd(game->moves, 1);
	ft_putchar_fd('\n', 1);
	game->moves++;
}

int	ft_move(t_game *game, int key)
{
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

void	ft_move_player(t_game *game, int x, int y)
{
	if (game->map[game->py + y][game->px + x] == '1')
		return ;
	if (game->map[game->py + y][game->px + x] == 'C')
	{
		game->map[game->py + y][game->px + x] = '0';
		ft_draw_map(game, GROUND, (game->py + y) * 64, (game->px + x) * 64);
		game->score++;
	}
	if (game->map[game->py + y][game->px + x] == 'E')
	{
		if (game->score == game->coins)
			game->status = WIN;
		else
			return ;
	}
	ft_print_move(game);
	game->px = game->px + x;
	game->py = game->py + y;
}
