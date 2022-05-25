/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaffron <ksaffron@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:58:54 by ksaffron          #+#    #+#             */
/*   Updated: 2022/05/25 16:02:20 by ksaffron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_game_init(t_game *game)
{
	ft_correct_map(game->map);
	ft_get_info(game);
	ft_wrapped_map(game);
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, game->length * 64, \
	game->height * 64, "so_long");
	ft_draw_img(game);
}
