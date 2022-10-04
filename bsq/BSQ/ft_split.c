/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguilbea <gguilbea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 19:08:51 by gguilbea          #+#    #+#             */
/*   Updated: 2022/10/03 20:08:01 by gguilbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_separateur(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset [i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_size_word(char *str, int i, char *charset)
{
	int	len;

	len = 0;
	while (str[i])
	{
		if (ft_separateur(str[i], charset))
			return (len);
		len++;
		i++;
	}
	return (len);
}

int	ft_count_word(char *str, char *charset)
{
	int	start;
	int	i;
	int	count_word;

	i = 0;
	start = 0;
	count_word = 0;
	while (str[i])
	{
		if (ft_separateur(str[i], charset))
			start = 0;
		else if (!ft_separateur(str[i], charset) && start == 0)
		{
			start = 1;
			count_word++;
		}
		i++;
	}
	return (count_word);
}

char	**ft_split2(char *str, char *charset, char **tab, int i)
{
	int	c;
	int	index;

	c = 0;
	index = 0;
	while (str[++i])
	{
		if (ft_separateur(str[i], charset) && (!(ft_separateur(str[i + 1], \
		charset))) && index > 0)
		{
			c++;
			index = 0;
		}
		if (!(ft_separateur(str[i], charset)))
		{
			if (index == 0)
				tab[c] = malloc(sizeof(char) * \
				ft_size_word(str, i, charset) + 1);
			tab[c][index] = str[i];
			tab[c][index + 1] = 0;
			index++;
		}
	}
	tab[ft_count_word(str, charset)] = NULL;
	return (tab);
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int		i;

	i = -1;
	tab = malloc(sizeof(char *) * ft_count_word(str, charset) + 1);
	tab = ft_split2(str, charset, tab, i);
	return (tab);
}
