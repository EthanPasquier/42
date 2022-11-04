/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epasquie <epasquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 08:57:09 by epasquie          #+#    #+#             */
/*   Updated: 2022/11/03 15:23:48 by epasquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, t_s *test)
{
	if (n == -2147483648)
	{
		ft_putchar('-', test);
		ft_putchar('2', test);
		ft_putnbr(147483648, test);
	}
	else
	{
		if (n < 0)
		{
			ft_putchar('-', test);
			n *= -1;
		}
		if (n > 9)
		{
			ft_putnbr(n / 10, test);
			ft_putnbr(n % 10, test);
		}
		else
			ft_putchar(n + 48, test);
	}
}

void	ft_unsigned_putnbr(unsigned int n, t_s *test)
{
	if (n < 0)
	{
		ft_putchar('-', test);
		n *= -1;
	}
	if (n > 9)
	{
		ft_unsigned_putnbr(n / 10, test);
		ft_unsigned_putnbr(n % 10, test);
	}
	else
		ft_putchar(n + 48, test);
}

int	ft_printf(const char *format, ...)
{
	int			mem;
	va_list		args;
	struct s_s	test;

	va_start(args, format);
	mem = -1;
	test.purc = 0;
	test.compt = 0;
	while (*format)
	{
		if (*format == '%' && mem < 0 && test.purc == 0)
			mem = 1;
		else if ((*format == 'd' || *format == 'i' || *format == 'u'
				|| *format == 'c' || *format == 's' || *format == 'x'
				|| *format == 'X' || *format == 'p') && mem > 0)
			mem = ft_conversion(mem, *format, args, &test);
		else
		{
			ft_putchar(*format, &test);
			mem = -1;
		}
		format++;
	}
	va_end(args);
	return (test.compt);
}
