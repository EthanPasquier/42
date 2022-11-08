/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epasquie <epasquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 10:22:10 by epasquie          #+#    #+#             */
/*   Updated: 2022/11/08 16:57:02 by epasquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

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

void	*ft_calloc(int count, int size)
{
	char	*str;
	int		i;

	str = malloc(size * count);
	if (!str)
		return (0);
	i = -1;
	while (++i < (size * count))
		str[i] = 0;
	return ((void *)str);
}

static char	*ft_sauv(char *lignefinal)
{
	char	*sauvegarde;
	int		compt;

	compt = 0;
	while (lignefinal[compt] != '\n' && lignefinal[compt] != '\0')
		compt++;
	if (lignefinal[compt] == '\0')
		return (0);
	sauvegarde = ft_substr(lignefinal, compt + 1, ft_strlen(lignefinal)
			- compt);
	if (sauvegarde[0] == '\0')
	{
		free(sauvegarde);
		sauvegarde = NULL;
	}
	lignefinal[compt + 1] = '\0';
	return (sauvegarde);
}

static char	*ft_parse(int fd, char *buf, char *sauv)
{
	int		read_line;
	char	*tmp;

	read_line = 1;
	while (read_line > 0)
	{
		read_line = read(fd, buf, BUFFER_SIZE);
		if (read_line == -1)
			return (0);
		else if (read_line == 0)
			break ;
		buf[read_line] = '\0';
		if (!sauv)
			sauv = ft_calloc(sizeof(char), 1);
		tmp = sauv;
		sauv = ft_strjoin(tmp, buf);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (sauv);
}

char	*get_next_line(int fd)
{
	char		*lignefinale;
	static char	*sauv;
	char		*buf;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
	{
		if (sauv > 0) // a patch , mal free
			free(sauv);
		return (0);
	}
	buf = ft_calloc(sizeof(char) * (BUFFER_SIZE + 1), 1);
	if (!buf)
		return (0);
	lignefinale = ft_parse(fd, buf, sauv);
	free(buf);
	buf = NULL;
	if (!lignefinale)
		return (NULL);
	sauv = ft_sauv(lignefinale);
	return (lignefinale);
}
