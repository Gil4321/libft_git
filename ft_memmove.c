/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adghouai <adghouai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 13:38:39 by adghouai          #+#    #+#             */
/*   Updated: 2025/11/12 14:12:15 by adghouai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (dst > src)
	{
		len--;
		while (len >= 0)
		{
			((unsigned char *)dst)[len] = ((unsigned char *)src)[len];
			len--;
		}
	}
	else
	{
		while (i < len)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
}
