/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epasquie <epasquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 11:36:25 by epasquie          #+#    #+#             */
/*   Updated: 2022/11/08 15:56:42 by epasquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_s
{
	char	*sauvegarde;
	int		nbl;
	int		ret;
	char	*buf;
}			t_s;

char		*get_next_line(int fd);
char		*ft_makechar(char *buf, int compt);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t		ft_strlen(const char *str);
char		*ft_strjoin(char const *s1, char const *s2);
void		*ft_calloc(int count, int size);
char		*ft_strdup(char *src);
char		*ft_substr(char const *s, unsigned int start, size_t len);

#endif
