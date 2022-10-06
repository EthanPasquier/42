/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epasquie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 12:03:54 by epasquie          #+#    #+#             */
/*   Updated: 2022/10/04 12:43:28 by epasquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int	*str;
	int	i;

	i = 0;
	if (min >= max)
	{
		str = NULL;
		return (str);
	}
	str = malloc((max - min) * (sizeof(int)));
	if (str == 0)
		return (0);
	while (min < max)
	{
		str[i] = min;
		min++;
		i++;
	}
	return (str);
}
