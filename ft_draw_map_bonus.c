/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaffron <ksaffron@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:59:03 by ksaffron          #+#    #+#             */
/*   Updated: 2022/05/25 19:35:53 by ksaffron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_draw_map_bonus(t_game_b *game, char *asset, int x, int y)
{
	void	*img;
	int		img_height;
	int		img_width;

	img = mlx_xpm_file_to_image(game->mlx, asset, &img_width, &img_height);
	mlx_put_image_to_window(game->mlx, game->window, img, x, y);
}


int	ft_draw_img_bonus(t_game_b *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->length)
		{
			ft_draw_map_bonus(game, BOX, 0, 0);
			ft_draw_map_bonus(game, GROUND, x * 64, y * 64);
			if (game->map[y][x] == '1')
				ft_draw_map_bonus(game, WALL, x * 64, y * 64);
			else if (game->map[y][x] == 'C')
				ft_draw_map_bonus(game, TREAT, x * 64, y * 64);
			x++;
		}
		y++;
	}
	return (0);
}

// int	ft_next_frame(t_game_b *game)
// {
// 	static int	fps = -150;
// 	char		*steps;

// 	steps = ft_itoa(game->moves);
// 	mlx_string_put(game->mlx, game->window, 20, 20, 0x0066FF33, steps);
// 	free(steps);
// 	if (game->map[y][x] == 'B')
// 		ft_draw_map(game, ENEMY, x * 64, y * 64);
// }
