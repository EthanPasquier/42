/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epasquie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:23:17 by epasquie          #+#    #+#             */
/*   Updated: 2022/10/19 17:23:20 by epasquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi2(unsigned int i, unsigned long long ret, unsigned int negative)
{
	if (i > 19 && ret > 18446744071562067968ULL)
	{
		if (negative == 1)
			return (-1);
		return (0);
	}
	return ((int)ret * negative);
}

int	ft_atoi(const char *str)
{
	unsigned int		i;
	unsigned long long	ret;
	unsigned int		negative;

	i = 0;
	negative = 1;
	ret = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negative = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		ret = ret * 10 + (str[i] - '0');
		i++;
	}
	return (ft_atoi2(i, ret, negative));
}
