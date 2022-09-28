/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epasquie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:18:35 by epasquie          #+#    #+#             */
/*   Updated: 2022/09/16 11:46:13 by epasquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_check(int *tab, int nb)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < nb - 1)
	{
		while (j < nb)
		{
			if (tab[j] == tab[i] || tab[i] > tab[j])
				return (1);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (0);
}

void	ft_print_tab(int nb, int *tab)
{
	int		i;
	char	c;

	i = -1;
	while (++i < nb)
	{
		c = tab[i] + 48;
		write(1, &c, 1);
	}
}

int	*ft_compteur(int	*tab, int nb)
{
	int	i;

	i = nb;
	tab[nb - 1]++;
	while (--i > 0)
	{
		if (tab[i] > 10 - nb + i)
		{
			tab[i - 1]++;
			tab[i] = tab[i - 1];
			i = nb;
		}
	}
	if (ft_check (tab, nb) == 0)
		return (tab);
	else
		ft_compteur(tab, nb);
	return (0);
}

void	ft_print_comb(void)
{
	int	nb;
	int	i;
	int	tab[3];

	nb = 3;
	i = -1;
	while (++i < nb)
	{
		tab[i] = i;
	}
	ft_print_tab(nb, tab);
	while (tab[0] < (10 - nb))
	{
		write(1, ",", 1);
		write(1, " ", 1);
		ft_compteur(tab, nb);
		ft_print_tab(nb, tab);
	}
}
