/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaffron <ksaffron@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 15:05:05 by ksaffron          #+#    #+#             */
/*   Updated: 2022/05/26 17:56:30 by ksaffron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_draw_img(t_game *game, char *asset, int x, int y)
{
	void	*img;
	int		img_height;
	int		img_width;

	img = mlx_xpm_file_to_image(game->mlx, asset, &img_width, &img_height);
	mlx_put_image_to_window(game->mlx, game->window, img, x, y);
}

int	ft_draw_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->length)
		{
			ft_draw_img(game, GROUND, x * 64, y * 64);
			if (game->map[y][x] == 'E')
				ft_draw_img(game, STONE, x * 64, y * 64);
			else if (game->map[y][x] == '1')
				ft_draw_img(game, WALL, x * 64, y * 64);
			else if (game->map[y][x] == 'P')
				ft_draw_img(game, PLAYER, x * 64, y * 64);
			else if (game->map[y][x] == 'C')
				ft_draw_img(game, TREAT, x * 64, y * 64);
			x++;
		}
		y++;
	}
	return (0);
}
