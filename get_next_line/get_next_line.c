/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epasquie <epasquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 10:22:10 by epasquie          #+#    #+#             */
/*   Updated: 2022/11/04 07:22:46 by epasquie         ###   ########.fr       */
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

char	*get_next_line(int fd)
{
	int			ret;
	char		*buf;
	char		*sauvfinal;
	int			i;
	int			j;
	static char	*sauvegarde;
	static int	nbl;

	if (nbl > fd || !BUFFER_SIZE)
		return (NULL);
	sauvfinal = malloc(sizeof(char));
	sauvfinal[0] = 0;
	if (sauvegarde)
	{
		sauvfinal = ft_strjoin(sauvfinal, sauvegarde);
		free(sauvegarde);
	}
	buf = malloc((BUFFER_SIZE) * sizeof(char));
	buf[BUFFER_SIZE] = 0;
	i = 0;
	while (!(ft_strchr(buf, '\n')))
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret < BUFFER_SIZE)
			break ;
		sauvfinal = ft_strjoin(sauvfinal, buf);
	}
	if (ret < BUFFER_SIZE)
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
	free(buf);
	nbl++;
	return (sauvfinal);
}
