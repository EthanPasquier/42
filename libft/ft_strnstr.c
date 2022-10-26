/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epasquie <epasquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:09:01 by epasquie          #+#    #+#             */
/*   Updated: 2022/10/24 17:12:58 by epasquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	i;

	i = -1;
	if (ft_strlen(needle) == 0 || (!haystack && len == 0))
		return ((char *)haystack);
	while (haystack[++i] != '\0' && len >= ft_strlen(needle))
	{
		if (haystack[i] == needle[0])
		{
			if (ft_check((char *)&haystack[i], (char *)needle))
				return ((char *)&haystack[i]);
		}
		len--;
	}
	return (0);
}
