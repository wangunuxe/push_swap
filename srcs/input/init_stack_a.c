/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jili <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:15:33 by jili              #+#    #+#             */
/*   Updated: 2025/04/07 14:15:50 by jili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static long	my_atoi_long(const char *str)
{
	int		sign;
	long	result;
	int		i;

	sign = 1;
	result = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

static t_stack_node	*create_new_node(long n)
{
	t_stack_node	*new_node;

	new_node = malloc(sizeof(t_stack_node));
	if (new_node == NULL)
		return (NULL);
	new_node->number = n;
	new_node->next = new_node;
	new_node->pre = new_node;
	new_node->cheapest = 0;
	return (new_node);
}

static void	append_to_stack(t_stack_node **pp_head, long n)
{
	t_stack_node	*new_node;
	t_stack_node	*last_node;

	new_node = create_new_node(n);
	if (!(*pp_head))
	{
		*pp_head = new_node;
		new_node->next = new_node;
		new_node->pre = new_node;
	}
	else
	{
		last_node = find_last(*pp_head);
		last_node->next = new_node;
		new_node->next = *pp_head;
		(*pp_head)->pre = new_node;
		new_node->pre = last_node;
	}
}

void	init_stack_a(t_stack_node	**pp_head, char **array)
{
	long	n;
	int		i;

	i = 0;
	while (array[i])
	{
		if (error_syntax(array[i]) == -1)
			printerror_free(pp_head);
		n = my_atoi_long(array[i]);
		if (error_duplicate_bigger_smaller(pp_head, n) == -1)
			printerror_free(pp_head);
		append_to_stack(pp_head, n);
		i++;
	}
}
