/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsnew.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epasquie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 10:50:17 by epasquie          #+#    #+#             */
/*   Updated: 2022/10/24 10:50:19 by epasquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*lt;

	lt = malloc(sizeof(t_list));
	if (!lt)
		return (0);
	lt->content = content;
	lt->next = NULL;
	return (lt);
}
