/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguilbea <gguilbea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 11:56:25 by gguilbea          #+#    #+#             */
/*   Updated: 2022/10/05 19:38:28 by gguilbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>

# define BUFF_SIZE 1001008
# define FALSE 0

typedef struct info
{
	int		nbl;
	int		nbc;
	int		valide;
	int		ip;
	char	cv;
	char	obs;
	char	sqr;
	char	**tab;
	char	**copy;
}t_info;

typedef struct soluce
{
	int	trow;
	int	fcol;
	int	srow;
	int	scol;
	int	lcol;
	int	lrow;
	int	nrow;
	int	ncol;
	int	maxcol;
	int	exit;
}t_soluce;

int			ft_atoi(char *str);
int			ft_solve(t_info *ptr);
int			soluce2(t_soluce *soluce, t_info *ptr, int row, int col);
int			soluce3(t_soluce *soluce, t_info *ptr, int row, int col);
int			ft_assign_char2(char *buf, t_info *test);
int			ft_checkline2(char *buf, int i, t_info *test, int colone);
int			ft_nbl(char *buf, t_info *test);
void		ft_print(t_info *ptr);
void		ft_putstr(char *str);
void		ft_putchar(char c);
char		**ft_split(char *str, char *charset);
char		*ft_strdup(char *src);
t_soluce	*ft_get_max(t_soluce *soluce);
t_soluce	*set_soluce_val(t_soluce *soluce, int row, int col);
t_soluce	*ft_square_found(t_info *ptr, int row, int col, t_soluce *soluce);

#endif
