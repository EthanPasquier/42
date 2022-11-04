/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epasquie <epasquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 12:18:44 by epasquie          #+#    #+#             */
/*   Updated: 2022/11/03 15:53:27 by epasquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlendst(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

static size_t	ft_strlensrc(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len;

	if (dst == 0 && dstsize == 0)
		return (dstsize + ft_strlensrc(src));
	len = ft_strlendst(dst);
	if (dstsize <= len)
		return (dstsize + ft_strlensrc(src));
	dstsize -= len + 1;
	while (*src && *src != '\n' && dstsize-- > 0)
	{
		dst[len++] = *src++;
		dst[len] = 0;
	}
	if (*src == '\n' && dstsize-- > 0)
	{
		dst[len++] = *src++;
		dst[len] = 0;
	}
	return (len + ft_strlensrc(src));
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
