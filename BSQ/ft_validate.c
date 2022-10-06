/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguilbea <gguilbea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 11:53:19 by epasquie          #+#    #+#             */
/*   Updated: 2022/10/05 13:06:38 by gguilbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_nbl(char *buf, t_info *test)
{
	int		i;
	char	*charnbl;

	i = 0;
	while ((buf[i] >= '0' && buf[i] <= '9') && i < test->ip)
		i++;
	charnbl = malloc(i * sizeof(int));
	i = 0;
	while ((buf[i] >= '0' && buf[i] <= '9') && i < test->ip)
	{
		charnbl[i] = buf[i];
		i++;
	}
	test->nbl = ft_atoi(charnbl);
	return (i);
}

int	ft_assign_char(char *buf, int i, t_info *test)
{
	int	compt;

	compt = 3;
	while (buf[i] != '\n')
		i++;
	i--;
	while (compt > 0)
	{
		if (compt == 1)
		{
			test->ip = i;
			test->cv = buf[i];
		}
		if (compt == 2)
			test->obs = buf[i];
		if (compt == 3)
			test->sqr = buf[i];
		i--;
		compt--;
	}
	return (ft_assign_char2(buf, test));
}

int	ft_checkline(char *buf, int i, t_info *test)
{
	int	colone;

	colone = 0;
	while (buf[i] != '\n' && buf[i] != '\0')
	{
		colone++;
		i++;
	}
	test->nbc = colone;
	i -= colone;
	return (ft_checkline2(buf, i, test, colone));
}

int	ft_validate(t_info *test, char **argv, int index)
{
	int		ret;
	char	buf[BUFF_SIZE + 1];
	int		fd;
	int		i;
	int		compt;

	compt = -1;
	i = 0;
	fd = open(argv[index], O_RDONLY);
	ret = read(fd, buf, BUFF_SIZE);
	buf[ret] = '\0';
	i = ft_assign_char(buf, i, test);
	if (test->valide == 1)
		return (1);
	if (ft_checkline(buf, i, test) == 0)
	{
		test->valide = 1;
		return (1);
	}
	test->tab = ft_split(buf, "\n");
	test->copy = test->tab;
	return (0);
}

int	main(int argc, char **argv)
{
	int			i;
	t_info		test;
	t_soluce	soluce;

	i = 1;
	while (i < argc)
	{
		ft_validate(&test, argv, i);
		soluce.maxcol = 0;
		if (test.valide == 1)
			ft_putstr("Map error");
		else
		{
			ft_solve(&test);
			ft_putchar('\n');
		}
		i++;
	}
}
