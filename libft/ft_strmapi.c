/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epasquie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 18:14:53 by epasquie          #+#    #+#             */
/*   Updated: 2022/10/21 18:14:54 by epasquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpytkt(char *des, const char *sr)
{
	size_t	i;

	i = 0;
	while (sr[i] != '\0')
	{
		des[i] = sr[i];
		i++;
	}
	des[i] = '\0';
	return (des);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*result;

	if (s == NULL || f == NULL)
		return (0);
	result = malloc(ft_strlen(s) + 1);
	if (!result)
		return (0);
	ft_strcpytkt(result, s);
	i = 0;
	while (s[i])
	{
		result[i] = f(i, s[i]);
		i++;
	}
	return (result);
}
