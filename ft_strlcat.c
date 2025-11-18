/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adghouai <adghouai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:33:39 by adghouai          #+#    #+#             */
/*   Updated: 2025/11/18 15:30:28 by adghouai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	str_not_null(char *dst, size_t size)
{
	size_t	i;
	int		is_null;

	is_null = 0;
	i = 0;
	while (i < (size - 1))
	{
		if (dst[i] == '\0')
			is_null = 1;
		i++;
	}
	if (is_null == 1)
		return (1);
	return (0);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len_dst;
	size_t	res;

	j = 0;
	if (str_not_null(dst, size))
		return (size + strlen(src));
	i = strlen(dst);
	len_dst = strlen(dst);
	res = (strlen(dst) + strlen(src));
	while (j < (size - len_dst - 1) && src[j] != '\0')
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (res);
}
