/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jili <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:25:36 by jili              #+#    #+#             */
/*   Updated: 2025/03/28 16:25:40 by jili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include "../../Libft/libft.h"

void	ft_swap(t_stack_node **pp_head)
{
	t_stack_node	*p_first;
	t_stack_node	*p_second;
	t_stack_node	*p_third;
	t_stack_node	*p_last;

	if (!pp_head || !*pp_head || (*pp_head)->next == *pp_head)
		return ;
	p_first = *pp_head;
	p_second = (p_first)->next;
	if (p_second->next == p_first)
	{
		*pp_head = p_second;
		return ;
	}
	p_third = p_second->next;
	p_last = p_first->pre;
	p_first->next = p_third;
	p_first->pre = p_second;
	p_second->next = p_first;
	p_second->pre = p_last;
	p_third->pre = p_first;
	p_last->next = p_second;
	*pp_head = p_second;
}

void	sa(t_stack_node **a_head, bool print)
{
	ft_swap(a_head);
	if (!print)
		ft_printf("sa\n");
}

void	sb(t_stack_node **b_head, bool print)
{
	ft_swap(b_head);
	if (!print)
		ft_printf("sb\n");
}

void	ss(t_stack_node **a_head, t_stack_node **b_head, bool print)
{
	ft_swap(a_head);
	ft_swap(b_head);
	if (!print)
		ft_printf("ss\n");
}
