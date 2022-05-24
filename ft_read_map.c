/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaffron <ksaffron@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:23:10 by ksaffron          #+#    #+#             */
/*   Updated: 2022/05/24 14:59:48 by ksaffron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*strjoin_ft(char const *s1, char const *s2)
{
	char	*s3;
	int		i;

	i = 0;
	s3 = malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s3)
		return (NULL);
	while (s1 && s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	s3[i] = '\0';
	ft_strlcat(s3, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	return (s3);
}

static char	*get_next_line(char *file)
{
	int		fd;
	int		size;
	char	temp[BUFFER_SIZE + 1];
	char	*result;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error();
	size = 1;
	while (size)
	{
		size = read(fd, temp, BUFFER_SIZE);
		if (size < 0)
		{
			free(temp);
			return (NULL);
		}
		temp[size] = '\0';
		result = strjoin_ft(result, temp);
	}
	return (result);
}

void	ft_read_map(t_game *game, char *file)
{
	char	*line;
	char	*temp_line;
	char	**map1;
	int		count;
	int		j;

	count = 0;
	j = -1;
	line = get_next_line(file);
	temp_line = ft_strtrim(line, "\n");
	while (temp_line[++j])
		if (temp_line[j] == '\n')
			count++;
	j = -1;
	free(temp_line);
	map1 = ft_split(line, '\n');
	ft_check_lenght(map1);
	if (line)
		free(line);
	while (map1[++j])
		;
	if (count + 1 != j)
		ft_free_space(map1);
	if (count + 1 != j)
		ft_error();
	game->map = map1;
}
