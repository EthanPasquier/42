/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epasquie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:46:05 by epasquie          #+#    #+#             */
/*   Updated: 2022/09/28 17:46:06 by epasquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	ft_check_base(char *base)
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
		if ((base[i] >= 9 && base[i] <= 13) || base[i] == ' ')
			return (0);
		j = i + 1;
	}
	if (i <= 1)
		return (0);
	return (i);
}

int	ft_checka(char *str)
{
	if (*str >= '0' && *str <= '9')
		return (2);
	if (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\v'
		|| *str == '\f' || *str == '\r')
		return (1);
	if (*str == '-')
		return (3);
	if (*str == '+')
		return (4);
	else
		return (0);
}

int	ft_compt(char *str)
{
	int	tmp;
	int	i;

	tmp = 1;
	i = 0;
	while (str[i] != '\0' && (str[i] < '0' || str[i] > '9'))
	{
		if (ft_checka(&str[i]) == 3)
			tmp *= -1;
		if (ft_checka(&str[i]) == 1 && ft_checka(&str[i - 1]) > 2)
			return (0);
		if (ft_checka(&str[i]) == 0)
			return (0);
		i++;
	}
	return (i * tmp);
}

int	ft_is_good(char *str, char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (base[j] != '\0')
	{
		if (str[i] == base[j])
			return (j);
		j++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	nb;
	int	signe;

	i = 0;
	nb = 0;
	signe = 1;
	if (ft_check_base(base) == 0)
		return (0);
	i = ft_compt(str);
	while (i < 0)
	{
		i *= -1;
		signe *= -1;
	}
	while (ft_is_good(&str[i], base) != -1)
	{
		nb *= ft_check_base(base);
		nb += ft_is_good(&str[i], base);
		i++;
	}
	return (nb * signe);
}
