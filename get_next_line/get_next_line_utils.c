/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epasquie <epasquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 12:18:44 by epasquie          #+#    #+#             */
/*   Updated: 2022/11/02 11:15:34 by epasquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
// static void	*ft_calloc(size_t count, size_t size)
// {
// 	char	*str;
// 	size_t	i;

// 	str = malloc(size * count);
// 	if (!str)
// 		return (0);
// 	i = -1;
// 	while (++i < (size * count))
// 		str[i] = 0;
// 	return ((void *)str);
// }

char	*ft_makechar(char *buf, int compt)
{
	char		*str;
	int			i;
	static int	ptr;

	i = 0;
	str = malloc((compt) * sizeof(char));
	while (i < compt)
	{
		str[i] = buf[ptr];
		ptr++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
