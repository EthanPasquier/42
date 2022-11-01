/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epasquie <epasquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 10:22:10 by epasquie          #+#    #+#             */
/*   Updated: 2022/11/01 15:01:30 by epasquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	int			ret;
	char		*buf;
	int			compt;
	static int	ptr;

	compt = 0;
	buf = malloc(BUFFER_SIZE);
	ret = read(fd, buf, BUFFER_SIZE);
	while (buf[ptr] != '\n' && compt <= BUFFER_SIZE)
	{
		compt++;
		ptr++;
	}
	return (ft_makechar(buf, compt));
}
