/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adghouai <adghouai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 12:50:18 by adghouai          #+#    #+#             */
/*   Updated: 2025/11/12 13:41:09 by adghouai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strdup(const char *str)
{
	size_t	i;
	char	*str2;

	i = 0;
	while (str[i])
	{
		i++;
	}
	str2 = malloc((sizeof(char) * i) + 1);
	if (str2 == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		str2[i] = str[i];
		i++;
	}
	str2[i] = '\0';
	return (str2);
}
