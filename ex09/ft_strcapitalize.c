/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epasquie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 16:05:56 by epasquie          #+#    #+#             */
/*   Updated: 2022/09/20 11:21:19 by epasquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

char	*ft_strlowcase(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] +32;
		}
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	tmp;

	i = -1;
	tmp = 1;
	ft_strlowcase(str);
	while (str[++i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z' && tmp == 1)
		{
			str[i] -= 32;
			tmp = 0;
		}
		else if (str[i] >= '0' && str[i] <= '9')
			tmp = 0;
		else if (str[i] >= 'a' && str[i] <= 'z' && tmp == 0)
			tmp = 0;
		else
			tmp = 1;
	}
	return (str);
}
