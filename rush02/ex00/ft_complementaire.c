/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complementaire.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhan <marvin@42quebec.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 12:56:38 by makhan            #+#    #+#             */
/*   Updated: 2022/10/02 12:56:49 by makhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_centaine(long nb, char *buf);
void	ft_dizaine(long nb, char *buf);
void	ft_simple_nbr(long nb, char *buf);
void	ft_millier(char *buf, int index);

long	ft_iterative_power(long nb, int power)
{
	int		i;
	long	c;

	i = 1;
	c = nb;
	if (power == 0)
		return (1);
	if (power < 0 || nb == 0)
		return (0);
	while (++i <= power)
		nb *= c;
	return (nb);
}

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
		ft_putchar(str[i]);
}

void	ft_niveau(long nb, char *buf)
{
	int		i;
	long	tmp;

	i = 0;
	tmp = nb;
	while (tmp >= 1000)
	{
		tmp = tmp / 1000;
		i++;
	}
	if (tmp <= 20 && tmp > 0)
		ft_simple_nbr(tmp, buf);
	else if (tmp >= 21 && tmp <= 99)
		ft_dizaine(tmp, buf);
	else if (tmp >= 100 && tmp <= 999)
		ft_centaine(tmp, buf);
	if (nb > 999)
	{
		ft_putchar(' ');
		ft_millier(buf, i);
		ft_putchar(' ');
		ft_niveau(nb % ft_iterative_power(1000, i), buf);
	}
}
