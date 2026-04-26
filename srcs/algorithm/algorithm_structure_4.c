/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_structure_4.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jili <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:13:36 by jili              #+#    #+#             */
/*   Updated: 2025/04/07 14:13:42 by jili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	min_to_top(t_stack_node **pp_head)
{
	t_stack_node	*min_node;

	if (!pp_head || !(*pp_head))
		return ;
	min_node = find_min_node(*pp_head);
	if (!min_node || min_node == *pp_head)
		return ;
	move_to_top(pp_head, min_node, 'a');
}
