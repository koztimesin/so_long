/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaffron <ksaffron@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:59:07 by ksaffron          #+#    #+#             */
/*   Updated: 2022/05/25 16:02:21 by ksaffron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char **map)
{
	if (map)
		ft_free_space(map);
	ft_putstr_fd("Error\n", 1);
	exit(1);
}

int	ft_close_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	ft_free_space(game->map);
	exit(0);
}
