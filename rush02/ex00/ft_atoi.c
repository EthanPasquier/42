/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhan <marvin@42quebec.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 12:55:17 by makhan            #+#    #+#             */
/*   Updated: 2022/10/02 12:55:26 by makhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

int		ft_strlen(char *str);
void	ft_putstr(char *str);
int		ft_str_is_numeric(char *str);

long	ft_atoi(char *str)
{
	long	i;
	long	ret;
	int		negative;

	i = 0;
	negative = 1;
	ret = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negative *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		ret = ret * 10 + (str[i] - '0');
		i++;
	}
	return (ret);
}

int	ft_paremetre(int argc, char **argv, long *nb, int *fd)
{
	if (argc == 3 && ft_str_is_numeric(argv[2]) == 1
		&& ft_strlen(argv[2]) <= 10 && ft_atoi(argv[2]) <= 4294967295)
	{
		*fd = open(argv[1], O_RDONLY);
		*nb = ft_atoi(argv[2]);
	}
	else if (argc == 2 && ft_str_is_numeric(argv[1]) == 1
		&& ft_strlen(argv[1]) <= 10 && ft_atoi(argv[1]) <= 4294967295)
	{
		*fd = open("numbers.dict", O_RDONLY);
		*nb = ft_atoi(argv[1]);
	}
	else
	{
		ft_putstr("Error\n");
		return (1);
	}
	return (0);
}

int	ft_combzero(int index, char *buf, long nb)
{
	if (index == 1)
	{
		if (buf[nb] == '0' && buf[nb + 1] == '0' && buf[nb + 2] == '0')
			return (0);
	}
	if (index == 2)
	{
		if (buf[nb] == '0' && buf[nb + 1] == '0' && buf[nb + 2] == '0'
			&& buf[nb + 3] == '0' && buf[nb + 4] == '0' && buf[nb + 5] == '0')
			return (0);
	}
	if (index == 3)
	{
		if (buf[nb] == '0' && buf[nb + 1] == '0' && buf[nb + 2] == '0'
			&& buf[nb + 3] == '0' && buf[nb + 4] == '0' && buf[nb + 5] == '0'
			&& buf[nb + 6] == '0' && buf[nb + 7] == '0' && buf[nb + 8] == '0')
			return (0);
	}
	return (1);
}
