/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_structure_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jili <jili@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:19:13 by jili              #+#    #+#             */
/*   Updated: 2025/03/28 15:24:42 by jili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_stack_node	*extract_cheapest_node(t_stack_node **pp_head)
{
	t_stack_node	*node;

	if (!(*pp_head))
		return (NULL);
	node = *pp_head;
	while (node->next != *pp_head)
	{
		if (node->cheapest)
			return (node);
		node = node->next;
	}
	if (node->cheapest)
		return (node);
	return (NULL);
}

void	rotate_to_cheapest(t_stack_node **pp_head_a, \
	t_stack_node **pp_head_b, t_stack_node	*cheapest)
{
	t_stack_node	*target_of_cheapest;

	if (!pp_head_a || !pp_head_b || !(*pp_head_a) || !(*pp_head_b))
		return ;
	target_of_cheapest = cheapest->target_node;
	if (!target_of_cheapest)
		return ;
	steps_move_to_top(pp_head_a, cheapest);
	steps_move_to_top(pp_head_b, target_of_cheapest);
	while (*pp_head_a != cheapest && *pp_head_b != target_of_cheapest \
		&& cheapest->up == true && target_of_cheapest->up == true)
		rr(pp_head_a, pp_head_b, false);
}

void	rev_rotate_to_cheapest(t_stack_node **pp_head_a, \
	t_stack_node **pp_head_b, t_stack_node	*cheapest)
{
	t_stack_node	*target_of_cheapest;

	if (!pp_head_a || !pp_head_b || !(*pp_head_a) || !(*pp_head_b))
		return ;
	target_of_cheapest = cheapest->target_node;
	if (!target_of_cheapest)
		return ;
	steps_move_to_top(pp_head_a, cheapest);
	steps_move_to_top(pp_head_b, target_of_cheapest);
	while (*pp_head_a != cheapest && *pp_head_b != target_of_cheapest \
		&& cheapest->up == false && target_of_cheapest->up == false)
		rrr(pp_head_a, pp_head_b, false);
}

void	move_a_to_b(t_stack_node **pp_head_a, t_stack_node **pp_head_b)
{
	t_stack_node	*cheapest;
	t_stack_node	*target_of_cheapest;

	if (!pp_head_a || !(*pp_head_a))
		return ;
	cheapest = extract_cheapest_node(pp_head_a);
	if (!cheapest)
		return ;
	target_of_cheapest = cheapest->target_node;
	if (!target_of_cheapest)
		return ;
	if (cheapest->up == true && target_of_cheapest->up == true)
		rotate_to_cheapest(pp_head_a, pp_head_b, cheapest);
	else if (cheapest->up == false && target_of_cheapest->up == false)
		rev_rotate_to_cheapest(pp_head_a, pp_head_b, cheapest);
	move_to_top(pp_head_a, cheapest, 'a');
	move_to_top(pp_head_b, target_of_cheapest, 'b');
	pb(pp_head_a, pp_head_b, false);
}

void	move_b_to_a(t_stack_node **pp_head_a, t_stack_node **pp_head_b)
{
	t_stack_node	*target_of_head_b;

	if (!pp_head_a || !pp_head_b || !(*pp_head_a) || !(*pp_head_b))
		return ;
	target_of_head_b = (*pp_head_b)->target_node;
	if (!target_of_head_b)
		return ;
	move_to_top(pp_head_a, target_of_head_b, 'a');
	pa(pp_head_b, pp_head_a, false);
}
