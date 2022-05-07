/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaffron <ksaffron@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 15:05:05 by ksaffron          #+#    #+#             */
/*   Updated: 2022/05/07 15:09:32 by ksaffron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_draw_map(t_game *game, char *asset, int x, int y)
{
	void	*img;
	int		img_height;
	int		img_width;

	img = mlx_xpm_to_image(game->mlx, asset, &img_width, &img_height);
	mlx_put_image_to_window(game->mlx, game->window, img, x, y);
}

void	ft_draw_img(t_game *game)
{
	int	x, y = 0;

	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'E')
				ft_draw_map(game, EXIT, x, y);
			else if (game->map[y][x] == '1')
				ft_draw_map(game, WALL, x, y);
			else if (game->map[y][x] == 'P')
				ft_draw_map(game, PLAYER, x, y);
			else if (game->map[y][x] == 'C')
				ft_draw_map(game, TREAT, x ,y);
			else
				ft_draw_map(game, GROUND, x, y);
			x++;
		}
		y++;
	}
}
