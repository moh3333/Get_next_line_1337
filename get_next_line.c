/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthamir <mthamir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 14:16:12 by mthamir           #+#    #+#             */
/*   Updated: 2023/12/23 17:13:28 by mthamir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_get_buff(int fd, char *buffer)
{
	char	*ret;
	int		i;

	i = 1;
	while (i > 0)
	{
		ret = malloc (((size_t)BUFFER_SIZE + 1) * sizeof(char));
		if (!ret)
			return (free(buffer), NULL);
		i = read (fd, ret, BUFFER_SIZE);
		if (i == -1)
			return (free(buffer), free(ret), NULL);
		if (i == 0)
			return (free(ret), buffer);
		ret[i] = '\0';
		buffer = ft_strjoin(buffer, ret);
		if (!buffer)
			return (NULL);
		if (check_for_nl(&ret) == 1)
			break ;
	}
	return (buffer);
}

static int	get_i(char *tmp)
{
	int	i;

	i = 0;
	while (tmp[i] != '\n' && tmp[i] != '\0')
		i++;
	if (tmp[i] == '\n')
		i++;
	return (i);
}

static char	*get_line_(char *buffer)
{
	char	*ret;
	int		i;

	i = 0;
	i = get_i(buffer);
	ret = malloc ((i + 1) * sizeof(char));
	if (!ret)
		return (free(buffer), NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
	{
		ret[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		ret[i] = buffer[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

static char	*get_ready(char	*buffer, char *line)
{
	char	*ret;

	ret = ft_strdup(buffer + ft_strlen(line));
	return (free(buffer), ret);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || fd > OPEN_MAX || read (fd, buffer, 0) < 0 || BUFFER_SIZE <= 0)
		return (free(buffer), buffer = NULL, NULL);
	buffer = ft_get_buff(fd, buffer);
	if (!buffer || buffer [0] == 0)
		return (free(buffer), buffer = NULL, NULL);
	line = get_line_(buffer);
	if (!line || line [0] == 0)
		return (free(line), NULL);
	buffer = get_ready(buffer, line);
	return (line);
}
