/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epasquie <epasquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:13:02 by epasquie          #+#    #+#             */
/*   Updated: 2022/10/24 17:09:54 by epasquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*news;
	t_list	*tmp;

	if (!lst || !f)
		return (NULL);
	news = 0;
	while (lst)
	{
		tmp = ft_lstnew(lst);
		if (!tmp)
		{
			ft_lstclear(&lst, del);
			ft_lstclear(&news, del);
			return (NULL);
		}
		else
		{
			tmp->next = 0;
			tmp->content = f(lst->content);
			ft_lstadd_back(&news, tmp);
		}
		lst = lst->next;
	}
	free(lst);
	return (news);
}
