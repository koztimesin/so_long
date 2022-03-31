/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaffron <ksaffron@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:23:10 by ksaffron          #+#    #+#             */
/*   Updated: 2022/03/31 17:47:47 by ksaffron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*get_next_line(char *file)
{
	int		fd;
	int		size;
	char	temp[BUFFER_SIZE + 1];
	char	*result;

	fd = open(file, O_RDONLY);
	if (fd < 0 )
		ft_error();
	size = 1;
	while (size)
	{
		size = read(fd, temp, BUFFER_SIZE);
		if (fd < 0)
		{
			free(temp);
			return (NULL);
		}
		temp[size] = '\0';
		result = ft_strjoin(result, temp);
		if (!result)
		{
			free(result);
			return (NULL);
		}
	}
	return (result);
}

char	**ft_read_map(char *file)
{
	char	*line;
	char	**map;
	line = get_next_line(file);
	map = ft_split(line, '\n');
	if (!map)
	{
		free(map);
		return (NULL);
	}
	if (line)
		free(line);
	return (map);
}
