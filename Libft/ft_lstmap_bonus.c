/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jili <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 10:03:39 by jili              #+#    #+#             */
/*   Updated: 2024/12/02 18:38:34 by jili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*node;
	t_list	*list_n;

	if (!lst || !f || !del)
		return (NULL);
	tmp = lst;
	list_n = NULL;
	while (tmp)
	{
		node = ft_lstnew(f(tmp->content));
		if (!node)
		{
			ft_lstclear(&node, del);
			return (NULL);
		}
		ft_lstadd_back(&list_n, node);
		tmp = tmp->next;
	}
	return (list_n);
}
