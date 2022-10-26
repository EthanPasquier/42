/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epasquie <epasquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 08:54:08 by epasquie          #+#    #+#             */
/*   Updated: 2022/10/26 11:09:33 by epasquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_compteur(char const *s, char c)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (s && s[i])
	{
		if (s[i] != c)
		{
			nb++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (nb);
}

static int	ft_taille(char const *s, char c, int i)
{
	int	size;

	size = 0;
	while (s[i] != c && s[i])
	{
		size++;
		i++;
	}
	return (size);
}

static void	ft_free_tab(char **strs, int j)
{
	while (j-- > 0)
		free(strs[j]);
	free(strs);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**strs;
	int		size;
	int		j;

	i = 0;
	j = -1;
	strs = (char **)malloc((ft_compteur(s, c) + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	while (++j < ft_compteur(s, c))
	{
		while (s[i] == c)
			i++;
		size = ft_taille(s, c, i);
		strs[j] = ft_substr(s, i, size);
		if (!(strs[j]))
		{
			ft_free_tab(strs, j);
			return (NULL);
		}
		i += size;
	}
	strs[j] = 0;
	return (strs);
}
