/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solution.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguilbea <gguilbea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:25:09 by gguilbea          #+#    #+#             */
/*   Updated: 2022/10/05 19:55:59 by gguilbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_print_dev(t_info *ptr)
{
	int		row;
	int		col;
	t_info	tab;

	tab = *ptr;
	usleep(1500);
	system("clear");
	row = 1;
	while (row <= tab.nbl)
	{
		col = 0;
		while (col <= tab.nbc)
		{
			ft_putchar(tab.tab[row][col]);
			col++;
		}
		ft_putchar('\n');
		row++;
	}
}

void	ft_print(t_info *ptr)
{
	int	index;
	int	col;
	int	row;

	index = 0;
	col = 0;
	row = 1;
	while (row <= ptr->nbl)
	{
		col = 0;
		while (col < ptr->nbc)
		{
			ft_putchar(ptr->tab[row][col]);
			col++;
		}
		ft_putchar('\n');
		row++;
	}
}

t_soluce	*ft_square_found(t_info *ptr, int row, int col, t_soluce *soluce)
{
	set_soluce_val(soluce, row, col);
	while (soluce->ncol <= ptr->nbc && soluce->nrow <= ptr->nbl)
	{
		if (ptr->tab[soluce->nrow][soluce->ncol] == ptr->obs)
			return (soluce);
		row = soluce->nrow;
		if (soluce2(soluce, ptr, row, col))
			return (soluce);
		col = soluce->ncol;
		if (soluce3(soluce, ptr, row, col))
			return (soluce);
		if (soluce->nrow == ptr->nbl)
		{
			if (soluce->ncol - soluce->fcol + 1 > soluce->maxcol)
				ft_get_max(soluce);
		}
		soluce->nrow++;
		soluce->ncol++;
	}
	return (soluce);
}

void	ft_print_solution(t_soluce *soluce, t_info *ptr)
{
	int	endrow;
	int	endcol;
	int	row;
	int	col;

	col = soluce->scol;
	row = soluce->srow;
	endcol = soluce->scol + soluce->maxcol - 1;
	endrow = soluce->srow + soluce->maxcol - 1;
	while (row <= endrow)
	{
		col = soluce->scol;
		while (col <= endcol)
		{
			ptr->tab[row][col] = ptr->sqr;
			col++;
		}
		row++;
	}
	ft_print(ptr);
}

int	ft_solve(t_info *ptr)
{
	t_soluce	test;
	int			row;
	int			col;

	col = 0;
	row = 1;
	test.maxcol = 0;
	test.scol = 0;
	test.srow = 0;
	while (row <= ptr->nbl)
	{
		col = 0;
		while (col < ptr->nbc)
		{
			if (ptr->tab[row][col] != ptr->obs)
				ft_square_found(ptr, row, col, &test);
			col++;
		}
		row++;
	}
	ft_print_solution(&test, ptr);
	return (0);
}
