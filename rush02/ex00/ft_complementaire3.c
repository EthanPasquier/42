/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complementaire3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oletourn <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 14:54:24 by oletourn          #+#    #+#             */
/*   Updated: 2022/10/02 14:54:31 by oletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
int		ft_combzero(int index, char *buf, int nb);

void	ft_short(int i, char *buf)
{
	while (buf[++i] != ':')
		;
	while (buf[++i] == ' ')
		;
	i--;
	while (buf[++i] != '\n')
		ft_putchar(buf[i]);
}

void	ft_millier(char *buf, int index)
{
	int		i;
	int		j;
	int		bool;

	i = 0;
	j = 0;
	bool = 0;
	while (buf[i] != '\0' && bool == 0)
	{
		if (buf[i] == '1' && ft_combzero(index, buf, i + 1) == 0)
			bool = 1;
		else
			i++;
	}
	ft_short(i, buf);
}
