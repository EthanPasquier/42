/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epasquie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:59:20 by epasquie          #+#    #+#             */
/*   Updated: 2022/09/21 16:59:21 by epasquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_convert(unsigned int nbr, char *base, unsigned int size)
{
	if (nbr >= size)
		ft_convert(nbr / size, base, size);
	ft_putchar(base[nbr % size]);
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

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	i;
	unsigned int	nb;

	i = 0;
	if (nbr < 0)
	{
		ft_putchar('-');
		nb = nbr * -1;
	}
	else
		nb = nbr;
	while (base[i] != '\0')
		i++;
	if (ft_check(base))
		ft_convert(nb, base, i);
}
