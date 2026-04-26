/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_new_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jili <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:14:34 by jili              #+#    #+#             */
/*   Updated: 2025/04/07 14:14:43 by jili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

char	**ft_split_new(char *str, char separator)
{
	char	**arr;

	if (!str || !*str || num_of_words(str, separator) == 0)
		return (NULL);
	arr = (char **)malloc(sizeof(char *) * (num_of_words(str, separator) + 1));
	if (!arr)
		return (NULL);
	if (fill_split_array(str, separator, arr) == -1)
		return (NULL);
	return (arr);
}
