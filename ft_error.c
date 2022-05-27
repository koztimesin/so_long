/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaffron <ksaffron@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:59:07 by ksaffron          #+#    #+#             */
/*   Updated: 2022/05/27 16:27:46 by ksaffron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char **map)
{
	if (map)
		ft_free_space(map);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	ft_close_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	ft_free_space(game->map);
	exit(0);
}

void	ft_game_error(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	if (game->map)
		ft_free_space(game->map);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
