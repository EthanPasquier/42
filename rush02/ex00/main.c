/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oletourn <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 13:18:17 by oletourn          #+#    #+#             */
/*   Updated: 2022/10/02 13:18:27 by oletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#define BUFF_SIZE 4096

void	ft_split(long int nb, char *buf);
void	ft_niveau(long nb, char *buf);
int		ft_paremetre(int argc, char **argv, long *nb, int *fd);
long	ft_atoi(char *str);
long	ft_iterative_power(long nb, int power);
int		ft_str_is_numeric(char *str);
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
int		ft_is_dico(int nb, char *buf);
int		ft_combzero(int index, char *buf, int nb);
void	ft_short(int i, char *buf);
void	ft_millier(char *buf, int index);
void	ft_centaineshort(long nb, char *buf);
void	ft_simple_nbrshort(long nb, char *buf, int i);

void	ft_solonumero(long nb, char *buf)
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
		c = nb;
		if (buf[i] == c + 48 && (buf[i +1] == 32 || buf[i + 1] == ':')
			&& (buf[i - 1] == '\n' || i == 0))
			bool = 1;
		else
			i++;
	}
	while (buf[++i] != ':')
		;
	while (buf[++i] == ' ')
		;
	i--;
	while (buf[++i] != '\n')
		ft_putchar(buf[i]);
}

void	ft_simple_nbr(long nb, char *buf)
{
	int		i;
	int		j;	

	j = 0;
	i = 1;
	if (nb < 10)
		ft_solonumero(nb, buf);
	else
	{
		ft_simple_nbrshort(nb, buf, i);
	}
}

void	ft_dizaine(long nb, char *buf)
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
	ft_short(i, buf);
	if (nb % 10 > 0)
	{
		ft_putchar(' ');
		ft_simple_nbr(nb % 10, buf);
	}
}

void	ft_centaine(long nb, char *buf)
{
	int		i;
	int		j;
	int		bool;

	i = 0;
	j = 0;
	bool = 0;
	if (nb / 100 > 0)
		ft_simple_nbr(nb / 100, buf);
	ft_putchar(' ');
	while (buf[i] != '\0' && bool == 0)
	{
		if (buf[i] == '1' && buf[i + 1] == '0' && buf[i + 2] == '0'
			&& (buf[i + 3] == 32 || buf[i + 3] == ':'))
			bool = 1;
		else
			i++;
	}
	ft_short(i, buf);
	ft_centaineshort(nb, buf);
}

int	main(int argc, char **argv)
{
	long int		nb;
	int				ret;
	char			buf[BUFF_SIZE + 2];
	int				fd;

	if (ft_paremetre(argc, argv, &nb, &fd) == 1)
		return (0);
	ft_paremetre(argc, argv, &nb, &fd);
	ret = read(fd, buf, BUFF_SIZE);
	buf[ret + 1] = '\n';
	buf[ret + 2] = '\0';
	if (ft_is_dico(nb, &buf[0]) == 0)
	{
		ft_putstr("Dict Error\n");
		return (0);
	}
	ft_split(nb, buf);
	close(fd);
}
