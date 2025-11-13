/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adghouai <adghouai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:33:39 by adghouai          #+#    #+#             */
/*   Updated: 2025/11/12 14:14:02 by adghouai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	all_non_null(char *dst, size_t size)
{
	size_t	i;
	int		flag;

	flag = 0;
	i = 0;
	while (i < (size - 1))
	{
		if (dst[i] == '\0')
			flag = 1;
		i++;
	}
	if (flag == 1)
		return (1);
	return (0);
}

size_t	strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len_dst;
	int		res;

	j = 0;
	if (all_non_null(dst, size))
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
