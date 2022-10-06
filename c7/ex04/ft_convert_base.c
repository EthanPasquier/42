/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epasquie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:21:51 by epasquie          #+#    #+#             */
/*   Updated: 2022/09/28 14:21:52 by epasquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	ft_atoi_base(char *str, char *base);

char	*ft_reverse_string(char *tab, int size)
{
	int	i;
	int	tmp;

	i = 0;
	size = size - 1;
	while (i < size)
	{
		tmp = tab[i];
		tab[i] = tab[size];
		tab[size] = tmp;
		i++;
		size--;
	}
	return (tab);
}

char	*ft_convert(unsigned int nbr, char *base, unsigned int size, char *tab)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	if (tab[i] != 0)
		sign *= -1;
	while (nbr > 0)
	{
		tab[i] = (base[nbr % size]);
		nbr = nbr / size;
		i++;
	}
	if (sign < 0)
	{
		tab[i] = '-';
		i++;
	}
	if (i > 1)
		tab = ft_reverse_string(tab, i);
	return (tab);
}

char	*ft_check(char *base)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (base[++i] != 0)
	{
		while (base[++j] != 0)
		{
			if (base[i] == base[j])
				return (0);
		}
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
	}
	if (i <= 1)
		return (0);
	return (base);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	unsigned int	i;
	unsigned int	nb;
	int				result;
	char			*tab;
	int				sign;

	sign = 0;
	tab = (char *)malloc(100 * sizeof(char));
	result = ft_atoi_base(nbr, base_from);
	i = 0;
	if (result < 0)
	{
		tab[0] = '-';
		nb = result * -1;
	}
	else
		nb = result;
	while (base_to[i] != '\0')
		i++;
	if (ft_check(base_to))
		tab = (ft_convert(nb, base_to, i, tab));
	return (tab);
}
