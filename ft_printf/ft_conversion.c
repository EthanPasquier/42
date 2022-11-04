/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epasquie <epasquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:17:26 by epasquie          #+#    #+#             */
/*   Updated: 2022/10/28 10:19:54 by epasquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, t_s *test)
{
	write(1, &c, 1);
	test->compt++;
}

void	ft_putstr(char *str, t_s *test)
{
	int	i;

	i = -1;
	if (!str)
		ft_putstr("(null)", test);
	else
		while (str[++i] != '\0')
			ft_putchar(str[i], test);
}

int	ft_conversion(int mem, char format, va_list args, t_s *test)
{
	if ((format == 'd' || format == 'i' || format == 'u') && mem > 0)
	{
		if (format == 'u')
			ft_unsigned_putnbr(va_arg(args, unsigned int), test);
		else
			ft_putnbr(va_arg(args, int), test);
	}
	else if (format == 'c' && mem > 0)
		ft_putchar((va_arg(args, int)), test);
	else if (format == 's' && mem > 0)
		ft_putstr((va_arg(args, char *)), test);
	else if (format == 'x' && mem > 0)
		ft_convert((va_arg(args, int)), "0123456789abcdef", test);
	else if (format == 'X' && mem > 0)
		ft_convert((va_arg(args, int)), "0123456789ABCDEF", test);
	else if (format == 'p' && mem > 0)
	{
		ft_putstr("0x", test);
		ft_convertadrr((va_arg(args, unsigned long long)), "0123456789abcdef",
			test);
	}
	return (-1);
}
