/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jili <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:16:06 by jili              #+#    #+#             */
/*   Updated: 2025/04/07 14:16:10 by jili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include <stdio.h>

int	is_valid_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		if (!array[i][0] || error_syntax(array[i]) == -1)
		{
			write(2, "Error\n", 6);
			return (0);
		}
		i++;
	}
	return (1);
}

void	free_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

char	**parse_args(int argc, char **argv, int *is_split)
{
	char	**array;

	*is_split = 0;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (NULL);
	else if (argc == 2)
	{
		array = ft_split_new(argv[1], ' ');
		*is_split = 1;
		if (!is_valid_array(array))
		{
			free_array(array);
			return (NULL);
		}
	}
	else
		array = argv + 1;
	return (array);
}

int	main(int argc, char **argv)
{
	t_stack_node	*head_a;
	t_stack_node	*head_b;
	char			**array;
	int				is_split;

	head_a = NULL;
	head_b = NULL;
	is_split = 0;
	array = parse_args(argc, argv, &is_split);
	if (!array)
		exit (1);
	init_stack_a(&head_a, array);
	algori_sort_stacks(&head_a, &head_b);
	free_stack(&head_b);
	free_stack(&head_a);
	if (is_split)
		free_array(array);
	return (0);
}

/* int	main(int argc, char **argv)
{
	t_stack_node	*head_a;
	t_stack_node	*head_b;
	char			**array;
	int				is_split;

	head_a = NULL;
	head_b = NULL;
	is_split = 0;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
	{
		array = ft_split_new(argv[1], ' ');
		is_split = 1;
		if (!is_valid_array(array))
		{
			free_array(array);
			return (1);
		}
	}
	else
		array = argv + 1;
	init_stack_a(&head_a, array);
	algori_sort_stacks(&head_a, &head_b);
	free_stack(&head_b);
	free_stack(&head_a);
	if (is_split)
		free_array(array);
	return (0);
}
 */
