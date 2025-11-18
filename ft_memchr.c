/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adghouai <adghouai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:23:14 by adghouai          #+#    #+#             */
/*   Updated: 2025/11/18 15:08:38 by adghouai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (((unsigned char *)b)[i] && i < len)
	{
		if (((unsigned char *)b)[i] == (unsigned char)c)
			return (&((void *)b)[i]);
		i++;
	}
	return (0);
}
