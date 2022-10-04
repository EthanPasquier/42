/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguilbea <gguilbea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 11:56:25 by gguilbea          #+#    #+#             */
/*   Updated: 2022/10/03 20:27:15 by gguilbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>

int	ft_atoi(char *str);
void ft_putstr(char *str);
void ft_putchar(char c);
char	**ft_split(char *str, char *charset);

#define BUFF_SIZE 4096
#define FALSE 0
typedef struct info
{
	int nbl;//nombre de lignes
	int nbc;//nombre de colonnes
	char cv;//cases vides
	char obs;//obstacle
	char sqr;//signes du square
	int	valide;//(1 si le tableau n'est pas valide et 0 si il l'est)
	char **tab;//tableau copie
	int ip;//place de i quand il tend vers cv
}t_info;

# endif