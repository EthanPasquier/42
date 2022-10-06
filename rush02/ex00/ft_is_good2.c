/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_good2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epasquie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 19:06:52 by epasquie          #+#    #+#             */
/*   Updated: 2022/10/02 19:06:54 by epasquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_simple_nbr_dico2(char *buf, int i);
long	ft_dizaine_dico2(long nb, char *buf, int i);
int		ft_centaine_dico2(long nb, char *buf, int i, int compt);

int	ft_short_dico(int i, char *buf)
{
	while (buf[++i] != ':')
		;
	while (buf[++i] == ' ')
		;
	i--;
	while (buf[i] >= 32 && buf[i] <= 126)
		i++;
	if (buf[i] == '\n' || buf[i] == '\0')
		return (1);
	return (0);
}

int	ft_solonumero_dico(long nb, char *buf)
{
	int		i;
	int		bool;
	char	c;

	i = 0;
	bool = 0;
	while (buf[i] != '\0' && bool == 0)
	{
		c = nb;
		if (buf[i] == c + 48 && (buf[i + 1] == 32 || buf[i + 1] == ':')
			&& (buf[i - 1] == '\n' || i == 0))
			bool = 1;
		else
			i++;
	}
	if (buf[i] == '\0')
		return (0);
	while (buf[i] != ':')
		i++;
	i++;
	while (buf[i] >= 32 && buf[++i] <= 126)
		i++;
	if (buf[i] == '\n' || buf[i] == '\0')
		return (1);
	return (0);
}

long	ft_simple_nbr_dico(long nb, char *buf)
{
	int		i;
	int		j;
	int		bool;
	char	c;
	char	c2;

	j = 0;
	i = 1;
	bool = 0;
	if (nb < 10)
		return (ft_solonumero_dico(nb, buf));
	while (buf[i] != '\0' && bool == 0)
	{
		c = nb / 10;
		c2 = nb % 10;
		if (buf[i] == c + 48 && buf[i + 1] == c2 + 48
			&& (buf[i + 2] == 32 || buf[i + 2] == ':'))
			bool = 1;
		else
			i++;
	}
	return (ft_simple_nbr_dico2(buf, i));
}

long	ft_dizaine_dico(long nb, char *buf)
{
	int		i;
	int		j;
	int		bool;
	char	c;

	i = 0;
	j = 0;
	bool = 0;
	while (buf[i] != '\0' && bool == 0)
	{
		c = nb / 10;
		if (buf[i] == c + 48 && buf[i + 1] == '0'
			&& (buf[i + 2] == 32 || buf[i + 2] == ':'))
			bool = 1;
		else
			i++;
	}
	return (ft_dizaine_dico2(nb, buf, i));
}

int	ft_centaine_dico(long nb, char *buf)
{
	int		i;
	int		j;
	int		bool;
	int		compt;

	i = 0;
	j = 0;
	compt = 1;
	bool = 0;
	if (nb / 100 > 0)
		compt *= ft_simple_nbr_dico(nb / 100, buf);
	while (buf[i] != '\0' && bool == 0)
	{
		if (buf[i] == '1' && buf[i + 1] == '0' && buf[i + 2] == '0'
			&& (buf[i + 3] == 32 || buf[i + 3] == ':'))
			bool = 1;
		else
			i++;
	}
	return (ft_centaine_dico2(nb, buf, i, compt));
}
