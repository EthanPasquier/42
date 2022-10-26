/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epasquie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 10:57:17 by epasquie          #+#    #+#             */
/*   Updated: 2022/10/18 10:57:19 by epasquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *s, size_t n)
{
	unsigned long int	i;
	char				*tmp;

	tmp = s;
	i = 0;
	while (i < n)
	{
		*tmp = 0;
		tmp++;
		i++;
	}
	return (s);
}
