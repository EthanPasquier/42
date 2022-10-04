/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epasquie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 08:40:34 by epasquie          #+#    #+#             */
/*   Updated: 2022/09/20 08:40:36 by epasquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	len;

	len = ft_strlen(dest);
	if (size <= len)
	{
		return (size + ft_strlen(src));
	}
	size -= len + 1;
	while (*src && size-- > 0)
	{
		dest[len++] = *src++;
		dest[len] = 0;
	}
	return (len + ft_strlen(src));
}
