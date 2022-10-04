/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epasquie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:16:32 by epasquie          #+#    #+#             */
/*   Updated: 2022/09/21 16:16:34 by epasquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

int	ft_check(char *str)
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

int	ft_compt(char *str, int i, int nb)
{
	int	tmp;

	tmp = 1;
	while (str[i] != '\0')
	{
		if (ft_check(&str[i]) == 3 && ft_check(&str[i + i]) > 1)
			tmp *= -1;
		if (ft_check(&str[i]) == 1 && ft_check(&str[i - 1]) > 2)
			return (nb);
		else if (ft_check(&str[i]) == 2)
		{
			nb *= 10;
			nb += str[i] - 48;
		}
		else if (ft_check(&str[i]) == 0 || \
		(ft_check (&str[i]) == 4 && ft_check(&str[i - 1]) == 2))
			return (nb * tmp);
		i++;
	}
	return (nb * tmp);
}

int	ft_atoi(char *str)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	return (ft_compt(&str[i], i, nb));
}

int	main(void)
{
	printf("%d", ft_atoi("  -----+-54851  "));
}
