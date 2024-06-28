/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthamir <mthamir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:30:18 by mthamir           #+#    #+#             */
/*   Updated: 2023/12/23 17:33:18 by mthamir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (*s++ != 0)
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	size_t	i;
	char	*str;

	i = 0;
	str = NULL;
	if (s == NULL)
		return (NULL);
	i = ft_strlen(s);
	str = (char *) malloc ((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str = ft_copy(str, s, 0);
	str[i] = '\0';
	return (str);
}

char	*ft_copy(char *s1, char *s2, int i)
{
	int	j;

	j = 0;
	while (s2[j] != '\0')
		s1[i++] = s2[j++];
	return (s1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	char	*ret;
	int		i;

	str = NULL;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	i = ft_strlen(s1) + ft_strlen(s2);
	str = (char *) malloc ((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ret = str;
	str = ft_copy(str, s1, 0);
	str = ft_copy(str, s2, ft_strlen(s1));
	str[i] = '\0';
	free(s1);
	return (ret);
}

int	check_for_nl(char	**buff)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = *buff;
	while (tmp[i])
	{
		if (tmp[i] == '\n')
			return (free(*buff), 1);
		i++;
	}
	return (free(*buff), 0);
}