/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epasquie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:53:27 by epasquie          #+#    #+#             */
/*   Updated: 2022/10/19 11:53:29 by epasquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	c2;
	size_t	i;

	str = (char *)s;
	c2 = (char)c;
	i = ft_strlen(s);
	while (i > 0)
	{
		if (str[i] == c2)
			return (str + i);
		i--;
	}
	if (str[i] == c2)
		return (str);
	return (0);
}
