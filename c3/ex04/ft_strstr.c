/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epasquie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:07:27 by epasquie          #+#    #+#             */
/*   Updated: 2022/09/20 16:44:10 by epasquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_check(char *str, char *to_find)
{
	int	i;

	i = 0;
	while (to_find[i] != '\0')
	{
		if (to_find[i] != str[i])
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;

	i = -1;
	if (ft_strlen(to_find) == 0)
		return (str);
	while (str[++i] != '\0')
	{
		if (str[i] == to_find[0])
		{
			if (ft_check(&str[i], to_find))
				return (&str[i]);
		}
	}
	return (NULL);
}
