/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epasquie <epasquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 10:22:10 by epasquie          #+#    #+#             */
/*   Updated: 2022/11/04 04:09:18 by epasquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*ft_strncpy(char *des, const char *sr, size_t n)
{
	size_t	i;

	i = 0;
	while (sr[i] != '\0' && i + 1 < n)
	{
		des[i] = sr[i];
		i++;
	}
	if (i < n)
		des[i] = '\0';
	return (des);
}

static size_t	ft_strlentkt(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	ft_strncpy(dst, src, dstsize);
	return (ft_strlentkt(src));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!s1 || !s2)
		return (NULL);
	(str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1)));
	if (!str)
		return (0);
	ft_strlcpy(str, s1, s1_len + 1);
	ft_strlcat(str + (s1_len), s2, s2_len + 1);
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	if (c > 256)
		c %= 256;
	while (*s != c && *s != 0)
		s++;
	if (*s == 0 && c != 0)
		return (0);
	str = (char *)s;
	return (str);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;
	size_t	i;

	str = malloc(size * count);
	if (!str)
		return (0);
	i = -1;
	while (++i < (size * count))
		str[i] = 0;
	return ((void *)str);
}

char	*get_next_line(int fd)
{
	int			ret;
	char		*buf;
	char		*sauvfinal;
	int			i;
	int			j;
	static char	*sauvegarde;
	static int	nbl;

	if (nbl > fd)
		return (NULL);
	sauvfinal = malloc(sizeof(char));
	sauvfinal[0] = 0;
	if (sauvegarde)
	{
		sauvfinal = ft_strjoin(sauvfinal, sauvegarde);
		free(sauvegarde);
	}
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	buf[BUFFER_SIZE + 1] = 0;
	i = 0;
	while (!(ft_strchr(buf, '\n')))
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (!ret || ret < BUFFER_SIZE)
			break ;
		sauvfinal = ft_strjoin(sauvfinal, buf);
	}
	if (!ret || ret < BUFFER_SIZE)
	{
		free(buf);
		buf = malloc((ret) * sizeof(char));
		buf[ret] = 0;
		ret = read(fd, buf, ret);
		sauvfinal = ft_strjoin(sauvfinal, buf);
	}
	while (buf[i] != '\n' && i < BUFFER_SIZE && nbl < fd)
		i++;
	i++;
	if (i < BUFFER_SIZE && nbl < fd)
	{
		j = 0;
		sauvegarde = malloc(((BUFFER_SIZE - i) + 1) * sizeof(char));
		sauvegarde[(BUFFER_SIZE - i) + 1] = 0;
		while (i < BUFFER_SIZE)
		{
			sauvegarde[j] = buf[i];
			i++;
			j++;
		}
	}
	nbl++;
	return (sauvfinal);
}
