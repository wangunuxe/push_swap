/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jili <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 10:48:59 by jili              #+#    #+#             */
/*   Updated: 2024/12/02 17:59:49 by jili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	need_trim(char *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*new_str(const char *source, size_t start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (len <= 0 || start >= ft_strlen(source))
		return (ft_strdup(""));
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = source[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strtrim(const char *s1, char *set)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(s1) - 1;
	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	while (need_trim(set, s1[i]))
		i++;
	while (need_trim(set, s1[j]))
		j--;
	return (new_str(s1, i, j - i + 1));
}
