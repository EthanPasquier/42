/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguilbea <gguilbea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:28:51 by gguilbea          #+#    #+#             */
/*   Updated: 2022/10/05 19:29:15 by gguilbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_soluce	*ft_get_max(t_soluce *soluce)
{
	soluce->maxcol = soluce->ncol - soluce->fcol ;
	soluce->scol = soluce->fcol;
	soluce->srow = soluce->trow;
	return (soluce);
}

t_soluce	*set_soluce_val(t_soluce *soluce, int row, int col)
{
	soluce->trow = row;
	soluce->fcol = col;
	soluce->nrow = soluce->trow + 1;
	soluce->ncol = soluce->fcol + 1;
	return (soluce);
}

int	soluce2(t_soluce *soluce, t_info *ptr, int row, int col)
{
	row = soluce->nrow;
	while (col >= soluce->fcol)
	{
		if (ptr->tab[row][col] != ptr->obs)
			col--;
		else
		{
			if (soluce->ncol - soluce->fcol > soluce->maxcol)
				ft_get_max(soluce);
			soluce->exit = 1;
			return (1);
		}
	}
	return (0);
}

int	soluce3(t_soluce *soluce, t_info *ptr, int row, int col)
{
	col = soluce->ncol;
	while (row >= soluce->trow)
	{
		if (ptr->tab[row][col] != ptr->obs)
			row--;
		else
		{
			if (soluce->ncol - soluce->fcol > soluce->maxcol)
				ft_get_max(soluce);
			soluce->exit = 1;
			return (1);
		}
	}
	return (0);
}
