/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epasquie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 18:51:59 by epasquie          #+#    #+#             */
/*   Updated: 2022/09/17 19:10:43 by epasquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_rush(char c, int size, int x, int verif)
{
	int	i;

	i = 0;
	if (c == '*' && verif == 1)
		write(1, "/", 1);
	while (++i <= size)
	{
		write(1, &c, 1);
	}
	if (c == '*' && x > 1 && verif == 1)
		write(1, "\\", 1);
}

void	ft_last_line(int x, int y)
{
	if (y > 1)
	{
		write(1, "\\", 1);
		ft_print_rush('*', x -2, x, 0);
		write(1, "/", 1);
	}
}

void	rush(int x, int y)
{	
	int	i;

	i = 0;
	if (x > 0 && y > 0)
	{
		ft_print_rush('*', x -2, x, 1);
		ft_print_rush('\n', 1, x, 0);
		while (i < y -2)
		{
			if (x > 1)
			{
				ft_print_rush('*', 1, x,0);
				ft_print_rush(' ', x - 2, x,0);
			}
			ft_print_rush('*', 1, x, 0);
			ft_print_rush('\n', 1, x, 0);
			i++;
		}
		ft_last_line(x,y);
	}
}
