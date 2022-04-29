/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correctmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaffron <ksaffron@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 12:43:24 by ksaffron          #+#    #+#             */
/*   Updated: 2022/04/29 13:23:02 by ksaffron         ###   ########.fr       */
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
