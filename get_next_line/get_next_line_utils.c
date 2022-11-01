/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epasquie <epasquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 12:18:44 by epasquie          #+#    #+#             */
/*   Updated: 2022/11/01 14:59:31 by epasquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	*ft_calloc(size_t count, size_t size)
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

static char	*ft_makechar(char *buf, int compt)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(compt + 1);
	str[compt + 1] = '\0';
	while (i < compt)
	{
		str[i] = *buf;
		buf++;
		i++;
	}
	return (str);
}
