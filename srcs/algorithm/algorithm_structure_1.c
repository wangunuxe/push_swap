/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_structure_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jili <jili@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:52:32 by jili              #+#    #+#             */
/*   Updated: 2025/04/07 14:36:03 by jili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	count_forward_steps(t_stack_node **pp_head, t_stack_node *required_node)
{
	int				forward_steps;
	t_stack_node	*node;
	int				len_stack;

	forward_steps = 0;
	if (!pp_head || !(*pp_head) || !required_node)
		return (0);
	len_stack = stack_lenth(*pp_head);
	node = *pp_head;
	while (node != required_node && forward_steps < len_stack)
	{
		node = node->next;
		forward_steps++;
	}
	if (node != required_node)
		return (0);
	return (forward_steps);
}

int	count_backforward_steps(t_stack_node **pp_head, t_stack_node *required_node)
{
	int				backward_steps;
	t_stack_node	*node;
	int				len_stack;

	backward_steps = 0;
	if (!pp_head || !(*pp_head) || !required_node)
		return (0);
	len_stack = stack_lenth(*pp_head);
	node = *pp_head;
	while (node != required_node && backward_steps < len_stack)
	{
		node = node->pre;
		backward_steps++;
	}
	if (node != required_node)
		return (0);
	return (backward_steps);
}

static void	move_a_to_top(t_stack_node **pp_head, t_stack_node *required_node)
{
	int				forward_steps;
	int				backward_steps;

	forward_steps = count_forward_steps(pp_head, required_node);
	backward_steps = count_backforward_steps(pp_head, required_node);
	if (forward_steps == 0 || backward_steps == 0)
		return ;
	else if (forward_steps <= backward_steps)
		while (required_node != *pp_head)
			ra(pp_head, false);
	else
		while (required_node != *pp_head)
			rra(pp_head, false);
}

static void	move_b_to_top(t_stack_node **pp_head, t_stack_node *required_node)
{
	int				forward_steps;
	int				backward_steps;

	forward_steps = count_forward_steps(pp_head, required_node);
	backward_steps = count_backforward_steps(pp_head, required_node);
	if (forward_steps == 0 || backward_steps == 0)
		return ;
	else if (forward_steps <= backward_steps)
		while (required_node != *pp_head)
			rb(pp_head, false);
	else
		while (required_node != *pp_head)
			rrb(pp_head, false);
}

void	move_to_top(t_stack_node **pp_head, \
	t_stack_node *required_node, char stack_name)
{
	if (stack_name == 'a')
		move_a_to_top(pp_head, required_node);
	else if (stack_name == 'b')
		move_b_to_top(pp_head, required_node);
}
