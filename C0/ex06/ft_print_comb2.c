/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epasquie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 07:18:11 by epasquie          #+#    #+#             */
/*   Updated: 2022/09/15 15:58:36 by epasquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else if (nb <= 9)
		ft_putchar(nb + 48);
}

void	ft_print_ab(int a, int b)
{
	if (a < 10)
		ft_putchar('0');
	ft_putnbr(a);
	ft_putchar(' ');
	if (b < 10)
		ft_putchar('0');
	ft_putnbr(b);
	if (a < 98)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	b = 0;
	a = 0;
	while (a < 98)
	{
		b++;
		if (b > 99)
		{
			a++;
			b = a + 1;
		}
		ft_print_ab(a, b);
	}
}
