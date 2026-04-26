/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jili <jili@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:30:33 by jili              #+#    #+#             */
/*   Updated: 2025/01/15 10:12:28 by jili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_specifier(char spec, va_list args, int *p_len)
{
	if (spec == 'c')
		ft_word(va_arg(args, int), p_len);
	else if (spec == 'p')
		ft_pointer(va_arg(args, size_t), p_len);
	else if (spec == 's')
		ft_string(va_arg(args, char *), p_len);
	else if (spec == 'd' || spec == 'i')
		ft_number(va_arg(args, int), p_len);
	else if (spec == 'u')
		ft_unsigned(va_arg(args, unsigned int), p_len);
	else if (spec == 'x')
		ft_hex(va_arg(args, unsigned int), p_len, 'x');
	else if (spec == 'X')
		ft_hex(va_arg(args, unsigned int), p_len, 'X');
	else if (spec == '%')
		ft_word('%', p_len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ft_specifier(*format, args, &len);
			format++;
		}
		else
		{
			ft_word(*format, &len);
			format++;
		}
	}
	va_end (args);
	return (len);
}
