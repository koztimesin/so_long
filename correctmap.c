/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correctmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaffron <ksaffron@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 12:43:24 by ksaffron          #+#    #+#             */
/*   Updated: 2022/05/18 16:35:15 by ksaffron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "stdio.h"

void	ft_correctmap(char	**map)
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
				ft_error();
	}
}

void	ft_check_lenght(char **map)
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
			ft_error();
		y++;
	}
}
