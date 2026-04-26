/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_structure_3.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jili <jili@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:19:28 by jili              #+#    #+#             */
/*   Updated: 2025/03/28 15:27:09 by jili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static int	stack_sorted_ascending(t_stack_node *head)
{
	t_stack_node	*node;
	int				len;
	int				i;

	if (!head)
		return (0);
	node = head;
	len = stack_lenth(head);
	i = 0;
	while (i < len - 1)
	{
		if (node->number > node->next->number)
			return (-2);
		node = node->next;
		i++;
	}
	return (0);
}

static void	sort_three(t_stack_node **pp_head)
{
	t_stack_node	*max_node;

	if (!(*pp_head) || !pp_head)
		return ;
	max_node = find_max_node(*pp_head);
	if (max_node == (*pp_head)->next)
		rra(pp_head, false);
	else if (max_node == *pp_head)
		ra(pp_head, false);
	if ((*pp_head)->number > (*pp_head)->next->number)
		sa(pp_head, false);
	return ;
}

static void	algori_less_4(t_stack_node **pp_head_a, t_stack_node **pp_head_b)
{
	int	len_stack_a;

	if (!pp_head_a || !pp_head_b || !(*pp_head_a))
		return ;
	len_stack_a = stack_lenth(*pp_head_a);
	if (len_stack_a == 1)
		return ;
	else if (len_stack_a == 2)
	{
		if (stack_sorted_ascending(*pp_head_a) == -2)
			sa(pp_head_a, false);
	}
	else if (len_stack_a == 3)
	{
		if (stack_sorted_ascending(*pp_head_a) == -2)
			sort_three(pp_head_a);
	}
}

static void	algori_equal_greater_4(t_stack_node **pp_head_a, \
	t_stack_node **pp_head_b)
{
	int	len_stack_a;

	len_stack_a = stack_lenth(*pp_head_a);
	if (len_stack_a-- > 3 && stack_sorted_ascending(*pp_head_a) == -2)
		pb(pp_head_a, pp_head_b, false);
	if (len_stack_a-- > 3 && stack_sorted_ascending(*pp_head_a) == -2)
		pb(pp_head_a, pp_head_b, false);
	while (len_stack_a-- > 3 && stack_sorted_ascending(*pp_head_a) == -2)
	{
		init_node_a(*pp_head_a, *pp_head_b);
		move_a_to_b(pp_head_a, pp_head_b);
	}
	sort_three(pp_head_a);
	while (*pp_head_b)
	{
		init_node_b(*pp_head_b, *pp_head_a);
		move_b_to_a(pp_head_a, pp_head_b);
	}
	min_to_top(pp_head_a);
}

void	algori_sort_stacks(t_stack_node **pp_head_a, t_stack_node **pp_head_b)
{
	int	len_stack_a;

	if (!pp_head_a || !pp_head_b || !(*pp_head_a))
		return ;
	if (stack_sorted_ascending(*pp_head_a) == 0)
		return ;
	algori_less_4(pp_head_a, pp_head_b);
	len_stack_a = stack_lenth(*pp_head_a);
	if (len_stack_a >= 4)
		algori_equal_greater_4(pp_head_a, pp_head_b);
}
