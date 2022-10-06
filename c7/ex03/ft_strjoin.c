/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epasquie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:50:21 by epasquie          #+#    #+#             */
/*   Updated: 2022/10/05 19:50:26 by epasquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_add_strs_char(char *strs, char *s, int k)
{
	while (*strs)
	{
		s[k] = *strs;
		k++;
		strs++;
	}
	return (k);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strlens(char **str, int size)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (i < size)
	{
		len += ft_strlen(str[i]);
		i++;
	}
	return (len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		k;
	int		len;
	char	*s;

	if (size == 0)
		return ((char *)malloc(1));
	len = ft_strlens(strs, size) + 1 + (size - 1) * ft_strlen(sep);
	s = (char *)malloc(len * sizeof(char));
	if (!s)
		return (0);
	i = 0;
	k = 0;
	while (i < size && k < len)
	{
		k = ft_add_strs_char(strs[i], s, k);
		if (i < size - 1)
			k = ft_add_strs_char(sep, s, k);
		i++;
	}
	s[k] = '\0';
	return (s);
}
