/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epasquie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:27:08 by epasquie          #+#    #+#             */
/*   Updated: 2022/10/21 10:20:07 by epasquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned long int	i;
	char				*dstcpy;
	const char			*srccpy;

	i = 0;
	dstcpy = dst;
	srccpy = src;
	if (dst == 0 && src == 0)
		return (dst);
	while (i < n)
	{
		*dstcpy = *srccpy;
		srccpy++;
		dstcpy++;
		i++;
	}
	return (dst);
}
