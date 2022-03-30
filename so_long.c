/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaffron <ksaffron@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:14:43 by ksaffron          #+#    #+#             */
/*   Updated: 2022/03/30 16:02:06 by ksaffron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	char	*path = "./grass.xpm";
	// int		x;
	// int		y;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "so_long");
	img.img = mlx_new_image(mlx, 1001, 1001);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
	&img.line_length, &img.endian);
	// x = 0;
	// while (x <= 1000)
	// {
	// 	y = 0;
	// 	while (y <= 1000)
	// 	{
	// 		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
	// 		y++;
	// 	}
	// 	x++;
	// }
	img.img = mlx_xpm_file_to_image(mlx, path, 0, 0);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
