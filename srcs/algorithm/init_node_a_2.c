/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_node_a_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jili <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:09:08 by jili              #+#    #+#             */
/*   Updated: 2025/03/28 16:09:13 by jili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	reset_cheapest_flags(t_stack_node *head)
{
	t_stack_node	*node;

	if (!head)
		return ;
	node = head;
	while (1)
	{
		node->cheapest = false;
		node = node->next;
		if (node == head)
			break ;
	}
}

void	find_cheapest_node(t_stack_node *head)
{
	t_stack_node	*node;
	int				min_push_cost;
	t_stack_node	*is_cheapest_node;

	if (!head)
		return ;
	reset_cheapest_flags(head);
	node = head;
	min_push_cost = head->push_cost;
	is_cheapest_node = head;
	while (1)
	{
		if (node->push_cost < min_push_cost)
		{
			min_push_cost = node->push_cost;
			is_cheapest_node = node;
		}
		node = node->next;
		if (node == head)
			break ;
	}
	is_cheapest_node->cheapest = true;
}

void	init_node_a(t_stack_node *head_a, t_stack_node *head_b)
{
	find_target_of_a(head_a, head_b);
	push_cost(head_a, head_b);
	find_cheapest_node(head_a);
}
