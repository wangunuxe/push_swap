/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jili <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:30:58 by jili              #+#    #+#             */
/*   Updated: 2025/01/14 09:31:09 by jili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stddef.h>

int				ft_printf(const char *format, ...);
void			ft_word(char c, int *p_len);
void			ft_string(char *str, int *p_len);
void			ft_number(long nb, int *p_len);
void			ft_pointer(size_t pointer, int *p_len);
void			ft_hex(unsigned int nb, int *p_len, char x_X);
void			ft_unsigned(unsigned int nb, int *p_len);

#endif
