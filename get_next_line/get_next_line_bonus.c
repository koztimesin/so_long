/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaffron <ksaffron@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:00:38 by ksaffron          #+#    #+#             */
/*   Updated: 2022/01/11 15:20:42 by ksaffron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

static char	*ft_get_line(int fd, char *remains)
{
	char	*buffer;
	int		buffer_size;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!(buffer))
		return (NULL);
	buffer_size = 1;
	while (buffer_size && !(ft_strchr(remains, '\n')))
	{
		buffer_size = read(fd, buffer, BUFFER_SIZE);
		if (buffer_size <= 0)
		{
			break ;
			free(buffer);
			return (NULL);
		}
		buffer[buffer_size] = '\0';
		remains = ft_strjoin(remains, buffer);
	}
	free(buffer);
	return (remains);
}

static char	*ft_print_line(char *remains)
{
	int		i;
	char	*temp;

	i = 0;
	if (!(remains) || *remains == '\0')
		return (NULL);
	while (remains[i])
		if (remains[i++] == '\n')
			break ;
	temp = ft_substr(remains, 0, i);
	return (temp);
}

static char	*ft_get_new_line(char *remains)
{
	char	*temp;
	size_t	i;
	char	symbol_to_find;

	i = 0;
	if (!(remains) || *remains == '\0')
		return (NULL);
	symbol_to_find = '\n';
	while (remains[i])
		if (remains[i++] == '\n')
			break ;
	if (!(remains[i]))
	{
		free(remains);
		return (NULL);
	}
	if (!ft_strchr(remains, '\n'))
		symbol_to_find = '\0';
	temp = ft_substr(remains, i, ft_strlen(ft_strchr(remains, \
		symbol_to_find) + (symbol_to_find == '\n')));
	free(remains);
	return (temp);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*remains[257];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 256)
		return (NULL);
	remains[fd] = ft_get_line(fd, remains[fd]);
	line = ft_print_line(remains[fd]);
	remains[fd] = ft_get_new_line(remains[fd]);
	return (line);
}
