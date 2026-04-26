/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jili <jili@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:14:16 by jili              #+#    #+#             */
/*   Updated: 2025/04/07 14:36:35 by jili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	len_of_word(char *str, char separator)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != separator)
		i++;
	return (i);
}

int	num_of_words(char *str, char separator)
{
	int	count_num;
	int	i;

	count_num = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == separator)
			i++;
		if (str[i])
			count_num++;
		while (str[i] && str[i] != separator)
			i++;
	}
	return (count_num);
}

char	*get_word(char *str, char separator)
{
	int		len_word;
	char	*word;
	int		i;

	len_word = len_of_word(str, separator);
	word = (char *)malloc(len_word + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (i < len_word)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

void	free_words(char **arr, int index_current_word)
{
	int	i;

	i = 0;
	while (i < index_current_word)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	fill_split_array(char *str, char sep, char **arr)
{
	int	i;

	i = 0;
	while (*str)
	{
		while (*str == sep)
			str++;
		if (*str)
		{
			arr[i] = get_word(str, sep);
			if (!arr[i])
			{
				free_words(arr, i);
				return (-1);
			}
			str += len_of_word(str, sep);
			i++;
		}
	}
	arr[i] = NULL;
	return (0);
}
