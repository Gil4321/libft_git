/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adghouai <adghouai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:05:52 by adghouai          #+#    #+#             */
/*   Updated: 2025/11/12 14:30:42 by adghouai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i])
	{
		if (big[i] == little[0])
		{
			j = 1;
			while ((big[i + j] == little[j]) && (j < len))
			{
				j++;
			}
			if (little[j] == '\0' || j == len)
				return (&((char *)big)[i]);
		}
		i++;
	}
	return (0);
}
