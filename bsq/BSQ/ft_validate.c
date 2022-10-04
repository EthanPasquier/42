/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epasquie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 11:53:19 by epasquie          #+#    #+#             */
/*   Updated: 2022/10/03 11:53:20 by epasquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_nbl(char *buf, t_info *test)
{
	int	i;
	char *charnbl;
	
	i = 0;
	while((buf[i] >= '0' && buf[i] <= '9') && i < test->ip)
		i++;
	charnbl = malloc(i*sizeof(int));
	i = 0;
	while((buf[i] >= '0' && buf[i] <= '9') && i < test->ip)
	{
		charnbl[i] = buf[i];
		i++;
	}
	test->nbl = ft_atoi(charnbl);
	return (i);
}

int	ft_assign_char(char *buf, int i, t_info *test)
{
	int	compt;

	compt = 3;
	while(buf[i] != '\n')
		i++;
	i--;
	while(compt > 0)
	{
		if(compt == 1)
		{
			test->ip = i;
			test->cv = buf[i];
		}
		if(compt == 2)
			test->obs = buf[i];
		if(compt == 3)
			test->sqr = buf[i];
		i--;
		compt--;
	}
	i = 0;
	if(buf[0] >= '0' && buf[0] <= '9')
		i = ft_nbl(buf, test);
	else
		return (1);
	if(buf[i] == '\n')
		test->valide = 1;
	while(buf[i] != '\n' && buf[i] != '\0')
		i++;
	return (i+1);
}

int ft_checkline(char *buf, int i, t_info *test)
{
	int	compt;
	int	ligne;
	int colone;

	compt = 0;
	colone = 0;
	ligne = 1;
	while (buf[i] != '\n' && buf[i] != '\0')
	{
		colone++;
		i++;
	}
	test->nbc = colone;
	i -= colone;
	while (ligne < test->nbl || buf[i] != '\0')
	{

		printf("%c", buf[i]);
		if (buf[i] != test->obs && buf[i] != test->cv && buf[i] != '\n')
		{
			test->valide = 1;
			return(0);
		}
		if(buf[i] == '\n' && compt == colone)
		{
			compt = 0;
			ligne++;
			i++;
		}
		else
		{
			i++;
			compt++;
		}
	}
	if(ligne != test->nbl)
	{
		test->valide = 1;
		return(0);
	}
	return(1);
}

int ft_validate(t_info *test)
{
	int		ret;
	char 	buf[BUFF_SIZE + 1];
	int 	fd;
	int		i;
	int		compt;

	compt = -1;
	i = 0;
	fd = open("example_file", O_RDONLY);
	ret = read(fd, buf, BUFF_SIZE);
	buf[ret] = '\0';
	i = ft_assign_char(buf,i,test);
	if(test->valide == 1)
		return(1);
	if(ft_checkline(buf,i,test) == 0)
		return(1);
	test->tab = ft_split(buf, "\n");
	return (0);
}

int	main(void)
{
	t_info test;


	ft_validate(&test);
	if(test.valide == 1)
		printf("\n|TAB IS FALSE|\n");
	else
		printf("\n|TAB IS GOOD|\n");
	printf("- nbl = %i\n", test.nbl);
	printf("- nbc = %i\n", test.nbc);
	printf("- cv = %c\n", test.cv);
	printf("- obs = %c\n", test.obs);
	printf("- sqr = %c\n", test.sqr);
}