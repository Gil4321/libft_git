/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adghouai <adghouai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 12:03:20 by adghouai          #+#    #+#             */
/*   Updated: 2025/11/13 14:43:24 by adghouai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*calloc(size_t number, size_t size)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = malloc(number * size);
	while (ptr[i])
	{
		ptr[i] = 0;
		i++;
	}
	return ((void *)ptr);
}
