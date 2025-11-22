/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adghouai <adghouai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 18:41:42 by adghouai          #+#    #+#             */
/*   Updated: 2025/11/22 14:42:05 by adghouai         ###   ########lyon.fr   */
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

static int	calc_start(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (in_charset(set, s1[i]))
		i++;
	return (i);
}

static int	calc_end(char const *s1, char const *set)
{
	int	i;

	i = ft_strlen(s1) - 1;
	while (in_charset(set, s1[i]) && i >= 0)
		i--;
	return (i);
}

static char	*new_str(char const *s1, int start, int end)
{
	size_t	i;
	size_t	len;
	char	*result;

	i = 0;
	if (start > end)
		len = 0;
	else
		len = end - start + 1;
	result = malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	while (start <= end)
	{
		result[i] = s1[start];
		start++;
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	int		start;
	int		end;

	if (!s1 || !set)
		return (NULL);
	start = calc_start(s1, set);
	end = calc_end(s1, set);
	result = new_str(s1, start, end);
	return (result);
}

/* #include <stdio.h>
int	main(void)
{
	char	*s;
	s = ft_strtrim("", "");
	printf("%s", s);
} */
