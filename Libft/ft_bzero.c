/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jili <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:09:44 by jili              #+#    #+#             */
/*   Updated: 2024/11/29 13:12:36 by jili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "libft.h"*/

void	ft_bzero(void *s, int n)
{
	unsigned char	*p;

	p = s;
	while (n--)
		*p++ = 0;
}
/*
#include<stdio.h>

int	main(void)
{
	char str[50];

	ft_bzero(str, 10);
	printf("%s\n", str);
	return (0);
}*/
