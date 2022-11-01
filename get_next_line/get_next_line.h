/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epasquie <epasquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 11:36:25 by epasquie          #+#    #+#             */
/*   Updated: 2022/11/01 15:00:47 by epasquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

// typedef struct s_s
// {
// 	int	comptbuf;
// 	int	refer;
// }		t_s;

char		*get_next_line(int fd);
static char	*ft_makechar(char *buf, int compt);

#endif
