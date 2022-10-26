/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epasquie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:57:58 by epasquie          #+#    #+#             */
/*   Updated: 2022/10/18 16:58:00 by epasquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *des, const char *sr, size_t n)
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

size_t	ft_strlentkt(const char *str)
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
