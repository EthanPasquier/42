/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epasquie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:45:07 by epasquie          #+#    #+#             */
/*   Updated: 2022/10/05 18:45:08 by epasquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_assign_char2(char *buf, t_info *test)
{
	int	i;

	i = 0;
	if (buf[0] >= '0' && buf[0] <= '9')
		i = ft_nbl(buf, test);
	else
		return (1);
	if (buf[i] == '\n')
		test->valide = 1;
	while (buf[i] != '\n' && buf[i] != '\0')
		i++;
	return (i + 1);
}

int	ft_checkline2(char *buf, int i, t_info *test, int colone)
{
	int	compt;
	int	ligne;

	compt = 0;
	ligne = 1;
	while (ligne < test->nbl || buf[i] != '\0')
	{
		if (buf[i] != test->obs && buf[i] != test->cv && buf[i] != '\n')
		{
			test->valide = 1;
			return (0);
		}
		if (buf[i] == '\n' && buf[i + 1] != '\0' && compt == colone)
		{
			compt = 0;
			ligne++;
		}
		else
			compt++;
		i++;
	}
	if (ligne != test->nbl)
		test->valide = 1;
	return (1);
}
