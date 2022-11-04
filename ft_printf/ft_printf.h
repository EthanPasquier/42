/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epasquie <epasquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 10:10:09 by epasquie          #+#    #+#             */
/*   Updated: 2022/11/02 14:38:45 by epasquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <unistd.h>

# define BUFF_SIZE 0

typedef struct s_s
{
	int	compt;
	int	purc;
}		t_s;

void	ft_putnbr_base(int nbr, char *base, t_s *test);
void	ft_putchar(char c, t_s *test);
int		ft_conversion(int mem, char format, va_list args, t_s *test);
void	ft_putstr(char *str, t_s *test);
void	ft_unsigned_putnbr(unsigned int n, t_s *test);
void	ft_putnbr(int n, t_s *test);
int		ft_printf(const char *format, ...);
void	ft_convertadrr(unsigned long int nbr, char *base, t_s *test);
void	ft_convert(unsigned int nbr, char *base, t_s *test);

#endif
