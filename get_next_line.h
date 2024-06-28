/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthamir <mthamir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 14:16:33 by mthamir           #+#    #+#             */
/*   Updated: 2023/12/23 19:49:28 by mthamir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif 

char	*get_next_line(int fd);
char	*ft_strjoin(char	*s1, char	*s2);
char	*ft_strdup(char *s);
size_t	ft_strlen(const char *s);
int		check_for_nl(char	**buff);
char	*ft_copy(char *s1, char *s2, int i);

#endif