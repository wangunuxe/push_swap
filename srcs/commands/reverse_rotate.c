/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jili <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:24:53 by jili              #+#    #+#             */
/*   Updated: 2025/03/28 16:24:59 by jili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include "../../Libft/libft.h"

static void	reverse_rotate(t_stack_node **pp_head)
{
	if (!(*pp_head) || !(*pp_head)->next)
		return ;
	if ((*pp_head)->next->next == *pp_head)
		ft_swap(pp_head);
	else
		*pp_head = (*pp_head)->pre;
}

void	rra(t_stack_node **a_head, bool print)
{
	reverse_rotate(a_head);
	if (!print)
		ft_printf("rra\n");
}

void	rrb(t_stack_node **b_head, bool print)
{
	reverse_rotate(b_head);
	if (!print)
		ft_printf("rrb\n");
}

void	rrr(t_stack_node **a_head, t_stack_node **b_head, bool print)
{
	reverse_rotate(a_head);
	reverse_rotate(b_head);
	if (!print)
		ft_printf("rrr\n");
}
