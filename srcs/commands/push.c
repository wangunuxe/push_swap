/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jili <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:24:40 by jili              #+#    #+#             */
/*   Updated: 2025/03/28 16:24:44 by jili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include "../../Libft/libft.h"

static void	remove_from_stack(t_stack_node **pp_head, t_stack_node *node)
{
	if (!pp_head || !*pp_head || !node)
		return ;
	if (node->next == node && node->pre == node)
		*pp_head = NULL;
	else if (node->next == NULL || node->pre == NULL)
	{
		return ;
	}
	else
	{
		node->pre->next = node->next;
		node->next->pre = node->pre;
		if (*pp_head == node)
			*pp_head = node->next;
	}
	node->next = NULL;
	node->pre = NULL;
}

void	push(t_stack_node **pp_head_src, t_stack_node **pp_head_dst)
{
	t_stack_node	*node;

	if (!pp_head_src || !*pp_head_src)
		return ;
	node = *pp_head_src;
	remove_from_stack(pp_head_src, node);
	if (!*pp_head_dst)
	{
		node->next = node;
		node->pre = node;
		*pp_head_dst = node;
	}
	else
	{
		node->next = *pp_head_dst;
		node->pre = (*pp_head_dst)->pre;
		(*pp_head_dst)->pre->next = node;
		(*pp_head_dst)->pre = node;
		*pp_head_dst = node;
	}
}

void	pa(t_stack_node **b_head, t_stack_node **a_head, bool print)
{
	push(b_head, a_head);
	if (!print)
		ft_printf("pa\n");
}

void	pb(t_stack_node **a_head, t_stack_node **b_head, bool print)
{
	push(a_head, b_head);
	if (!print)
		ft_printf("pb\n");
}
