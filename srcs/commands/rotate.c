/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jili <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:25:13 by jili              #+#    #+#             */
/*   Updated: 2025/03/28 16:25:17 by jili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include "../../Libft/libft.h"

static void	rotate(t_stack_node **pp_head)
{
	if (!*pp_head || !(*pp_head)->next)
		return ;
	if ((*pp_head)->next->next == *pp_head)
		ft_swap(pp_head);
	else
		*pp_head = (*pp_head)->next;
}

void	ra(t_stack_node **a_head, bool print)
{
	rotate(a_head);
	if (!print)
		ft_printf("ra\n");
}

void	rb(t_stack_node **b_head, bool print)
{
	rotate(b_head);
	if (!print)
		ft_printf("rb\n");
}

void	rr(t_stack_node **a_head, t_stack_node **b_head, bool print)
{
	rotate(a_head);
	rotate(b_head);
	if (!print)
		ft_printf("rr\n");
}
