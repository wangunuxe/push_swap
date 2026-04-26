/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_node_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jili <jili@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:39:01 by jili              #+#    #+#             */
/*   Updated: 2025/03/28 16:18:33 by jili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static t_stack_node	*find_closest_bigger_in_a(t_stack_node *node_b, \
	t_stack_node *head_a)
{
	long			closest_bigger_number;
	t_stack_node	*node_a;
	t_stack_node	*target;

	if (!head_a || !node_b)
		return (NULL);
	closest_bigger_number = LONG_MAX;
	target = NULL;
	node_a = head_a;
	while (1)
	{
		if (node_a->number > node_b->number && \
			node_a->number < closest_bigger_number)
		{
			closest_bigger_number = node_a->number;
			target = node_a;
		}
		node_a = node_a->next;
		if (node_a == head_a)
			break ;
	}
	if (!target)
		target = find_min_node(head_a);
	return (target);
}

static void	find_target_of_b(t_stack_node *head_b, t_stack_node *head_a)
{
	t_stack_node	*node_b;

	if (!head_a || !head_b)
		return ;
	node_b = head_b;
	while (1)
	{
		node_b->target_node = find_closest_bigger_in_a(node_b, head_a);
		node_b = node_b->next;
		if (node_b == head_b)
			break ;
	}
}

void	init_node_b(t_stack_node *head_b, t_stack_node *head_a)
{
	find_target_of_b(head_b, head_a);
}
