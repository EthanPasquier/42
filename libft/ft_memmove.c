/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epasquie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:49:52 by epasquie          #+#    #+#             */
/*   Updated: 2022/10/18 16:49:53 by epasquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*destination;
	const char	*source;

	destination = dst;
	source = src;
	if (len == 0 || source == destination)
		return (dst);
	if (destination < source)
		while (len--)
			*destination++ = *source++;
	else
	{
		source = (char *)source + (len - 1);
		destination = destination + (len - 1);
		while (len--)
			*destination-- = *source--;
	}
	return (dst);
}
