/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adghouai <adghouai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 18:10:26 by adghouai          #+#    #+#             */
/*   Updated: 2025/11/21 15:39:30 by adghouai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	count;
	size_t	len_s;

	len_s = ft_strlen(s);
	count = 0;
	if (!s)
		return (NULL);
	if (start >= len_s)
	{
		len = 0;
		start = 0;
	}
	else if (len > (len_s - start))
		len = (len_s - start);
	result = ft_calloc(len + 1, sizeof(char));
	if (result == NULL)
		return (NULL);
	while (s[start] && count < len)
	{
		result[count] = s[start];
		count++;
		start++;
	}
	return (result);
}

/*#include <stdio.h>

int	main(void)
{
	ft_substr("hola", -1, 0);
}*/