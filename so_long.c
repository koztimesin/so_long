/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaffron <ksaffron@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:14:43 by ksaffron          #+#    #+#             */
/*   Updated: 2022/02/05 21:19:13 by ksaffron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// static void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// }

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	t_data	img;
// 	int		x;
// 	int		y;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 1920, 1080, "so_long");
// 	img.img = "grass.xpm";
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
// 	&img.line_length, &img.endian);
// 	x = 5;
// 	while (x <= 400)
// 	{
// 		y = 5;
// 		while (y <= 400)
// 		{
// 			mlx_xpm_file_to_image(mlx, img.img, &x, &y);
// 			y++;
// 		}
// 		x++;
// 	}
// 	mlx_loop(mlx);
// }

// int	main(void)
// {
// 	void	*img;
// 	void	*mlx;

// 	mlx = mlx_init();
// 	img = mlx_new_image(mlx, 1920, 1080);
// 	mlx_loop(mlx);
// }

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
