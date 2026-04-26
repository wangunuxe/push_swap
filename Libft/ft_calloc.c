/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jili <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:09:50 by jili              #+#    #+#             */
/*   Updated: 2025/04/07 14:10:02 by jili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	*ft_malloc(size_t size)
{
	void	*tmp;
	size_t	i;

	i = 0;
	tmp = (void *)malloc(size);
	if (!tmp)
		return (NULL);
	while (i < size)
	{
		*(unsigned char *)(tmp + i) = 0;
		i++;
	}
	return (tmp);
}

void	*ft_calloc(size_t elements, size_t size)
{
	size_t	total_size;

	total_size = elements * size;
	if (!size && total_size / elements != size)
		return (NULL);
	return (ft_malloc(elements * size));
}
