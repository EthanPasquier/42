/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complementaire2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhan <marvin@42quebec.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 12:57:28 by makhan            #+#    #+#             */
/*   Updated: 2022/10/02 12:58:10 by makhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_centaine(long nb, char *buf);
void	ft_dizaine(long nb, char *buf);
void	ft_simple_nbr(long nb, char *buf);
void	ft_millier(char *buf, int index);
void	ft_putchar(char c);
void	ft_niveau(long nb, char *buf);
void	ft_short(int i, char *buf);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_split(long int nb, char *buf)
{
	if (nb <= 20)
		ft_simple_nbr(nb, buf);
	else if (nb >= 21 && nb <= 99)
		ft_dizaine(nb, buf);
	else if (nb >= 100 && nb <= 999)
		ft_centaine(nb, buf);
	else
		ft_niveau(nb, buf);
	ft_putchar('\n');
}

void	ft_centaineshort(long nb, char *buf)
{
	if (nb % 100 > 0 && nb % 100 <= 20)
	{
		ft_putchar(' ');
		ft_simple_nbr(nb % 100, buf);
	}
	else if (nb % 100 > 10)
	{
		ft_putchar(' ');
		ft_dizaine(nb % 100, buf);
	}
}

void	ft_simple_nbrshort(long nb, char *buf, int i)
{
	char	c;
	char	c2;
	int		bool;

	bool = 0;
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
	i++;
	ft_short(i, buf);
}
