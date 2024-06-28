/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthamir <mthamir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:55:37 by mthamir           #+#    #+#             */
/*   Updated: 2023/12/23 17:29:20 by mthamir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*buffer[OPEN_MAX];
	char		*line;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	if (fd < 0 || fd > OPEN_MAX)
		return (NULL);
	if (read (fd, buffer[fd], 0) < 0)
		return (free(buffer[fd]), buffer[fd] = NULL, NULL);
	buffer[fd] = ft_get_buff(fd, buffer[fd]);
	if (!buffer[fd] || buffer[fd][0] == 0)
		return (free(buffer[fd]), buffer[fd] = NULL, NULL);
	line = get_line_(buffer[fd]);
	if (!line || line [0] == 0)
		return (free(line), NULL);
	buffer[fd] = get_ready(buffer[fd], line);
	return (line);
}
