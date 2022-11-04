/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epasquie <epasquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:27:08 by epasquie          #+#    #+#             */
/*   Updated: 2022/10/28 10:13:56 by epasquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert(unsigned int nbr, char *base, t_s *test)
{
	if (nbr >= 16)
		ft_convert(nbr / 16, base, test);
	ft_putchar(base[nbr % 16], test);
}

void	ft_convertadrr(unsigned long int nbr, char *base, t_s *test)
{
	if (nbr >= 16)
		ft_convertadrr(nbr / 16, base, test);
	ft_putchar(base[nbr % 16], test);
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
