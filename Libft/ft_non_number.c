/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_non_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jili <jili@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:28:49 by jili              #+#    #+#             */
/*   Updated: 2025/01/15 10:11:38 by jili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_word(char c, int *p_len)
{
	write(1, &c, 1);
	(*p_len)++;
}

void	ft_string(char *str, int *p_len)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		*p_len += 6;
		return ;
	}
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		(*p_len)++;
		i++;
	}
}
