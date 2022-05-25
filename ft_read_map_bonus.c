/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaffron <ksaffron@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 19:22:31 by ksaffron          #+#    #+#             */
/*   Updated: 2022/05/25 19:25:53 by ksaffron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	char	*temp_result;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error(NULL);
	size = 1;
	while (size)
	{
		size = read(fd, temp, BUFFER_SIZE);
		if (size < 0)
			return (NULL);
		temp[size] = '\0';
		temp_result = result;
		result = strjoin_ft(temp_result, temp);
		free(temp_result);
	}
	return (result);
}

static void	check_map(t_game_b *game, char	*temp_line, char *line)
{
	int		count;
	int		i;
	char	**map;

	count = 0;
	i = -1;
	while (temp_line[++i])
		if (temp_line[i] == '\n')
			count++;
	i = -1;
	free(temp_line);
	map = ft_split(line, '\n');
	ft_check_length(map);
	if (line)
		free(line);
	while (map[++i])
		;
	if (count + 1 != i)
		ft_free_space(map);
	if (count + 1 != i)
		ft_error(NULL);
	game->map = map;
}

void	ft_read_map_bonus(t_game_b *game, char *file)
{
	char	*line;
	char	*temp_line;

	line = get_next_line(file);
	temp_line = ft_strtrim(line, "\n");
	check_map(game, temp_line, line);
}
