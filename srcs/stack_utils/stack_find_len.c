/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_find_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jili <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:16:34 by jili              #+#    #+#             */
/*   Updated: 2025/04/07 14:16:38 by jili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_stack_node	*find_last(t_stack_node *p_head)
{
	t_stack_node	*last_node;
	t_stack_node	*node;

	if (!p_head)
		return (NULL);
	last_node = p_head;
	node = p_head->next;
	while (node != p_head)
	{
		last_node = node;
		node = node->next;
	}
	return (last_node);
}

t_stack_node	*find_min_node(t_stack_node *p_head)
{
	long			nbr_min;
	t_stack_node	*node_min;
	t_stack_node	*node;

	if (!p_head)
		return (NULL);
	node_min = p_head;
	nbr_min = p_head->number;
	node = p_head->next;
	while (node != p_head)
	{
		if (node->number < nbr_min)
		{
			node_min = node;
			nbr_min = node_min->number;
		}
		node = node->next;
	}
	return (node_min);
}

t_stack_node	*find_max_node(t_stack_node *p_head)
{
	long			nbr_max;
	t_stack_node	*node_max;
	t_stack_node	*node;

	if (!p_head)
		return (NULL);
	node_max = p_head;
	nbr_max = p_head->number;
	node = p_head->next;
	while (node != p_head)
	{
		if (node->number > nbr_max)
		{
			nbr_max = node->number;
			node_max = node;
		}
		node = node->next;
	}
	return (node_max);
}

int	stack_lenth(t_stack_node *p_head)
{
	t_stack_node	*node;
	int				i;

	if (!p_head)
		return (0);
	if (p_head->next == p_head && p_head->pre == p_head)
		return (1);
	if (p_head->next->next == p_head)
		return (2);
	node = p_head;
	i = 1;
	while (node->next != p_head)
	{
		node = node->next;
		i++;
	}
	return (i);
}
