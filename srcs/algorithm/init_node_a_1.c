/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_node_a_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jili <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:09:21 by jili              #+#    #+#             */
/*   Updated: 2025/03/28 16:09:26 by jili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static t_stack_node	*find_closest_smaller_node_in_b(t_stack_node *node_a, \
	t_stack_node *head_b)
{
	long			closest_smaller_number;
	t_stack_node	*node_b;
	t_stack_node	*target;

	closest_smaller_number = LONG_MIN;
	node_b = head_b;
	target = NULL;
	if (!node_a || !head_b)
		return (NULL);
	while (1)
	{
		if (node_b->number < node_a->number && \
				node_b->number > closest_smaller_number)
		{
			closest_smaller_number = node_b->number;
			target = node_b;
		}
		node_b = node_b->next;
		if (node_b == head_b)
			break ;
	}
	if (!target)
		target = find_max_node(head_b);
	return (target);
}

void	find_target_of_a(t_stack_node *head_a, t_stack_node *head_b)
{
	t_stack_node	*node_a;

	if (!head_a || !head_b)
		return ;
	node_a = head_a;
	while (1)
	{
		node_a->target_node = find_closest_smaller_node_in_b(node_a, head_b);
		node_a = node_a->next;
		if (node_a == head_a)
			break ;
	}
}

int	steps_move_to_top(t_stack_node **pp_head, t_stack_node *required_node)
{
	int				forward_steps;
	int				backward_steps;

	if (!pp_head || !(*pp_head) || !required_node)
		return (-1);
	forward_steps = count_forward_steps(pp_head, required_node);
	backward_steps = count_backforward_steps(pp_head, required_node);
	if (forward_steps <= backward_steps)
	{
		required_node->up = true;
		return (forward_steps);
	}
	else
	{
		required_node->up = false;
		return (backward_steps);
	}
}

void	push_cost(t_stack_node *head_a, t_stack_node *head_b)
{
	int				push_cost_a;
	int				push_cost_target;
	t_stack_node	*node_a;

	if (!head_a || !head_b)
		return ;
	node_a = head_a;
	push_cost_a = 0;
	push_cost_target = 0;
	while (1)
	{
		push_cost_a = steps_move_to_top(&head_a, node_a);
		push_cost_target = steps_move_to_top(&head_b, node_a->target_node);
		if (push_cost_a == -1 || push_cost_target == -1)
			return ;
		node_a->push_cost = push_cost_a + push_cost_target;
		node_a = node_a->next;
		if (node_a == head_a)
			break ;
	}
}
