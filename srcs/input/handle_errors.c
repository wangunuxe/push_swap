/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jili <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:15:09 by jili              #+#    #+#             */
/*   Updated: 2025/04/07 14:15:15 by jili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	error_syntax(char *str)
{
	if (!str || *str == '\0')
		return (-1);
	if (!(*str == '+' || *str == '-' || (*str >= '0' && *str <= '9')))
		return (-1);
	if ((*str == '+' || *str == '-') && !(str[1] >= '0' && str[1] <= '9'))
		return (-1);
	if (*str == '+' || *str == '-')
		str++;
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (-1);
		str++;
	}
	return (0);
}

int	error_duplicate_bigger_smaller(t_stack_node **pp_head, long n)
{
	t_stack_node	*node;

	if (!(*pp_head))
		return (0);
	if (n > INT_MAX || n < INT_MIN)
		return (-1);
	node = *pp_head;
	while (node->next != *pp_head)
	{
		if (node->number == n)
			return (-1);
		node = node->next;
	}
	if (node->number == n)
		return (-1);
	return (0);
}

void	free_stack(t_stack_node **pp_head)
{
	t_stack_node	*node;
	int				i;
	int				len_stack;

	node = *pp_head;
	i = 0;
	len_stack = stack_lenth(*pp_head);
	while (i < len_stack - 1)
	{
		node = node->next;
		free(node->pre);
		i++;
	}
	free(node);
}

void	printerror_free(t_stack_node **pp_head)
{
	if (!(*pp_head) || !pp_head)
		return ;
	free_stack(pp_head);
	ft_printf("Error\n");
	exit(1);
}
