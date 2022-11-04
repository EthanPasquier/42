/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epasquie <epasquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 12:18:44 by epasquie          #+#    #+#             */
/*   Updated: 2022/11/04 07:05:03 by epasquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len;

	if (dst == 0 && dstsize == 0)
		return (dstsize + ft_strlen(src));
	len = ft_strlen((const char *)dst);
	if (dstsize <= len)
		return (dstsize + ft_strlen(src));
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
	return (len + ft_strlen(src));
}

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

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	ft_strncpy(dst, src, dstsize);
	return (ft_strlen(src));
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
