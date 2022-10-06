/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_good.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhan <marvin@42quebec.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 12:59:55 by makhan            #+#    #+#             */
/*   Updated: 2022/10/02 13:00:13 by makhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_short_dico(int i, char *buf);
int		ft_solonumero_dico(long nb, char *buf);
long	ft_simple_nbr_dico(long nb, char *buf);
long	ft_dizaine_dico(long nb, char *buf);
int		ft_centaine_dico(long nb, char *buf);
int		ft_combzero(int index, char *buf, int nb);
int		ft_iterative_power(long nb, int power);

int	ft_checkfin_dico(char *buf, int index)
{
	int	i;

	i = 0;
	index *= 3;
	while (i < index)
	{
		if (buf[i] == '\0' || buf[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	ft_combzero_dico(int index, char *buf, int nb)
{
	if (ft_checkfin_dico(buf, index) == 1)
		return (1);
	if (index == 1)
	{
		if (buf[nb] == '0' && buf[nb + 1] == '0' && buf[nb + 2] == '0')
			return (0);
	}
	if (index == 2)
	{
		if (buf[nb] == '0' && buf[nb + 1] == '0' && buf[nb + 2] == '0'
			&& buf[nb + 3] == '0' && buf[nb + 4] == '0' && buf[nb + 5] == '0')
			return (0);
	}
	if (index == 3)
	{
		if (buf[nb] == '0' && buf[nb + 1] == '0' && buf[nb + 2] == '0'
			&& buf[nb + 3] == '0' && buf[nb + 4] == '0' && buf[nb + 5] == '0'
			&& buf[nb + 6] == '0' && buf[nb + 7] == '0' && buf[nb + 8] == '0')
			return (0);
	}
	return (1);
}

int	ft_millier_dico(char *buf, int index)
{
	int		i;
	int		j;
	int		bool;

	i = 0;
	j = 0;
	bool = 0;
	while (buf[i] != '\0' && bool == 0)
	{
		if (ft_combzero_dico(index, buf, i + 1) == 1)
			return (1);
		if (buf[i] == '1' && ft_combzero_dico(index, buf, i + 1) == 0)
			bool = 1;
		else
			i++;
	}
	if (buf[i] == '\0')
		return (0);
	return (ft_short_dico(i, buf));
}

int	ft_niveau_dico(long nb, char *buf)
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
		ft_simple_nbr_dico(tmp, buf);
	else if (tmp >= 21 && tmp <= 99)
		ft_dizaine_dico(tmp, buf);
	else if (tmp >= 100 && tmp <= 999)
		ft_centaine_dico(tmp, buf);
	if (nb > 999)
	{
		ft_millier_dico(buf, i);
		ft_niveau_dico(nb % ft_iterative_power(1000, i), buf);
	}
	if (ft_millier_dico(buf, i) > 0)
		return (1);
	else
		return (0);
}

long	ft_is_dico(long nb, char *buf)
{
	int	comb;

	comb = 0;
	if (nb <= 20)
		comb = ft_simple_nbr_dico(nb, buf);
	else if (nb >= 21 && nb <= 99)
		comb = ft_dizaine_dico(nb, buf);
	else if (nb >= 100 && nb <= 999)
		comb = ft_centaine_dico(nb, buf);
	else
		comb = ft_niveau_dico(nb, buf);
	return (comb);
}
