/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_good3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epasquie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 19:41:19 by epasquie          #+#    #+#             */
/*   Updated: 2022/10/02 19:41:20 by epasquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_simple_nbr_dico(long nb, char *buf);
int		ft_solonumero_dico(long nb, char *buf);
long	ft_dizaine_dico(long nb, char *buf);

long	ft_simple_nbr_dico2(char *buf, int i)
{
	if (buf[i] == '\0')
		return (0);
	i++;
	while (buf[++i] != ':')
		;
	while (buf[++i] == ' ')
		;
	i--;
	while (buf[++i] >= 32 && buf[++i] <= 126)
		;
	if (buf[i] == '\n')
		return (1);
	return (0);
}

long	ft_dizaine_dico2(long nb, char *buf, int i)
{
	if (buf[i] == '\0')
		return (0);
	while (buf[++i] != ':')
		;
	while (buf[++i] == ' ')
		;
	i--;
	while (buf[++i] >= 32 && buf[++i] <= 126)
		;
	if (buf[i] != '\n')
		return (0);
	if (nb % 10 > 0)
		return (ft_simple_nbr_dico(nb % 10, buf));
	return (1);
}

int	ft_centaine_dico2(long nb, char *buf, int i, int compt)
{
	if (buf[i] == '\0')
		return (0);
	while (buf[++i] != ':')
		;
	while (buf[++i] >= 32 && buf[++i] <= 126)
		;
	if (nb % 100 > 0 && nb % 100 <= 20)
		compt *= ft_simple_nbr_dico(nb % 100, buf);
	else if (nb % 100 > 10)
		compt *= ft_dizaine_dico(nb % 100, buf);
	if (compt > 0)
		return (1);
	return (0);
}
