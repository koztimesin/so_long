/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_correct_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaffron <ksaffron@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 12:43:24 by ksaffron          #+#    #+#             */
/*   Updated: 2022/05/25 16:02:23 by ksaffron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "stdio.h"

void	ft_check_name(char *file)
{
	int	size;

	size = ft_strlen(file);
	if (ft_strncmp(&file[size - 4], ".ber\0", 5) || size < 5)
		ft_error(NULL);
}

void	ft_correct_map(char	**map)
{
	int	x;
	int	y;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
			if (map[y][x] != '1' && map[y][x] != '0' && map[y][x] != 'E'
			&& map[y][x] != 'C' && map[y][x] != 'P')
				ft_error(map);
	}
}

void	ft_check_length(char **map)
{
	int	x;
	int	y;
	int	len;

	y = 0;
	len = 0;
	while (map[0][len])
		len++;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
			x++;
		if (x != len)
			ft_error(map);
		y++;
	}
}

void	ft_wrapped_map(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map[0][x])
	{
		if (game->map[0][x] != '1' || game->map[game->height - 1][x] != '1')
			ft_error(game->map);
		x++;
	}
	while (game->map[y])
	{
		if (game->map[y][0] != '1' || game->map[y][game->length - 1] != '1')
			ft_error(game->map);
		y++;
	}
}
