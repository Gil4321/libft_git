/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adghouai <adghouai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:33:39 by adghouai          #+#    #+#             */
/*   Updated: 2025/11/19 17:24:08 by adghouai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	all_non_null(char *dst, size_t size)
{
	size_t	i;
	int		is_null;

	is_null = 0;
	i = 0;
	if (size <= 0)
		return (1);
	while (i <= (size - 1))
	{
		if (dst[i] == '\0')
			is_null = 1;
		i++;
	}
	if (is_null == 1)
		return (0);
	return (1);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len_dst;
	size_t	res;

	j = 0;
	if (all_non_null(dst, size))
		return (size + ft_strlen(src));
	i = ft_strlen(dst);
	len_dst = i;
	res = (ft_strlen(dst) + ft_strlen(src));
	while (j < (size - len_dst - 1) && src[j] != '\0')
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (res);
}
