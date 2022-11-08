/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epasquie <epasquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 12:18:44 by epasquie          #+#    #+#             */
/*   Updated: 2022/11/08 16:41:18 by epasquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	size_t	len;
	char	*ret;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	ret = malloc(len);
	if (!ret)
		return (NULL);
	while (i <= len && s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	while (i <= len && *s2)
	{
		ret[i] = *s2;
		i++;
		s2++;
	}
	// if (*s2 == '\n')
	// 	ret[i] = '\n';
	// i++;
	ret[i] = 0;
	return (ret);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*str;

	i = 0;
	while (src[i] != '\0')
		i++;
	str = malloc((i + 1) * sizeof(char));
	i = 0;
	while (src[i] != '\0')
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = 0;
	return (str);
}