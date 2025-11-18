/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adghouai <adghouai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 18:41:42 by adghouai          #+#    #+#             */
/*   Updated: 2025/11/18 16:02:54 by adghouai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_charset(const char *set, const char c)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static int	calc_str_len(char const *s1, char const *set)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(s1);
	while (s1[i])
	{
		if (in_charset(set, s1[i]))
			len--;
		i++;
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	i;
	size_t	len;

	len = calc_str_len(s1, set);
	result = malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (*s1)
	{
		if (in_charset(set, *s1) == 0)
		{
			result[i] = *s1;
			i++;
		}
		s1++;
	}
	result[i] = '\0';
	return (result);
}
