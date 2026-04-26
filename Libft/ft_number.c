/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jili <jili@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:29:52 by jili              #+#    #+#             */
/*   Updated: 2025/01/15 10:11:36 by jili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_number(long nb, int *p_len)
{
	if (nb < 0)
	{
		ft_word('-', p_len);
		nb = -nb;
	}
	if (nb > 9)
		ft_number(nb / 10, p_len);
	ft_word(nb % 10 + '0', p_len);
}

void	ft_pointer(size_t pointer, int *p_len)
{
	char	str[20];
	char	*base16;
	int		i;

	i = 0;
	base16 = "0123456789abcdef";
	if (pointer == 0)
	{
		write(1, "(nil)", 5);
		*p_len += 5;
		return ;
	}
	ft_word('0', p_len);
	ft_word('x', p_len);
	while (pointer != 0)
	{
		str[i] = base16[pointer % 16];
		pointer = pointer / 16;
		i++;
	}
	while (i--)
		ft_word(str[i], p_len);
}

void	ft_hex(unsigned int nb, int *p_len, char x_X)
{
	char	str[20];
	char	*base16;
	int		i;

	i = 0;
	if (x_X == 'x')
		base16 = "0123456789abcdef";
	else if (x_X == 'X')
		base16 = "0123456789ABCDEF";
	if (nb == 0)
		ft_word('0', p_len);
	while (nb != 0)
	{
		str[i] = base16[nb % 16];
		nb = nb / 16;
		i++;
	}
	while (i--)
	{
		ft_word(str[i], p_len);
	}
}

void	ft_unsigned(unsigned int nb, int *p_len)
{
	if (nb > 9)
		ft_unsigned(nb / 10, p_len);
	ft_word(nb % 10 + '0', p_len);
}
