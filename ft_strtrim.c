/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adghouai <adghouai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 18:41:42 by adghouai          #+#    #+#             */
/*   Updated: 2025/11/20 14:04:48 by adghouai         ###   ########lyon.fr   */
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

static size_t	calc_start(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	if (in_charset(set, s1[i]))
	{
		i++;
		while (in_charset(set, s1[i]))
			i++;
		return (i);
	}
	else
		return (i);
}

static size_t	calc_end(char const *s1, char const *set)
{
	size_t	i;

	i = ft_strlen(s1) - 1;
	if (in_charset(set, s1[i]) && i != 0)
	{
		i--;
		while (in_charset(set, s1[i]) && i != 0)
			i--;
		return (i);
	}
	else
		return (i);
}

static char	*new_str(char const *s1, size_t start, size_t end)
{
	size_t	i;
	size_t	len;
	char	*result;

	i = 0;
	if (start > end)
		len = 0;
	else
		len = end - start;
	result = malloc(sizeof(char) * (len + 2));
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
	size_t	start;
	size_t	end;

	if (!s1)
		return (NULL);
	start = calc_start(s1, set);
	end = calc_end(s1, set);
	result = new_str(s1, start, end);
	return (result);
}

/*int	main(void)
{
	printf("%s", ft_strtrim("          ", " "));
}*/
