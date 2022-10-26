/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epasquie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:04:07 by epasquie          #+#    #+#             */
/*   Updated: 2022/10/19 11:04:08 by epasquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
