/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epasquie <epasquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 10:22:10 by epasquie          #+#    #+#             */
/*   Updated: 2022/11/02 11:37:21 by epasquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	int			ret;
	char		*buf;
	static int	ptr;
	static int	compt;
	static char	*sauv;

	buf = malloc(BUFFER_SIZE);
	ret = read(fd, buf, BUFFER_SIZE);
	while(buf[compt] != '\n' && buf[compt] <= BUFFER_SIZE && buf[compt] != 0)
		compt++;
	
	return (0);
}
