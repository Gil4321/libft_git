/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adghouai <adghouai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 19:05:34 by adghouai          #+#    #+#             */
/*   Updated: 2025/11/18 15:22:53 by adghouai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	tab_count(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s == c)
		{
			while (*s == c)
				s++;
		}
		else
		{
			count++;
			while (*s != c && *s)
				s++;
		}
	}
	return (count);
}

static int	allocate_subtab(char **big_tab, char const *s, char c)
{
	size_t	word_len;

	word_len = 0;
	while (*s)
	{
		if (*s == c)
		{
			while (*s == c)
				s++;
		}
		else
		{
			while (*s != c && *s)
			{
				word_len++;
				s++;
			}
			*big_tab = malloc(sizeof(char) * (word_len + 1));
			if (*big_tab == NULL)
				return (0);
			word_len = 0;
			big_tab++;
		}
	}
	return (1);
}

static void	fill_subtab(char **big_tab, char const *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s == c)
		{
			while (*s == c)
				s++;
		}
		else
		{
			while (*s != c && *s)
			{
				(*big_tab)[i] = *s;
				i++;
				s++;
			}
			(*big_tab)[i] = '\0';
			i = 0;
			big_tab++;
		}
	}
}

static void	free_all(char **big_tab)
{
	while (*big_tab)
	{
		free(*big_tab);
	}
	free(big_tab);
}

char	**ft_split(char const *s, char c)
{
	char	**big_tab;
	size_t	nb_tab;

	nb_tab = tab_count(s, c);
	big_tab = malloc(sizeof(char *) * (nb_tab + 1));
	if (big_tab == NULL)
		return (NULL);
	big_tab[nb_tab] = NULL;
	if (!(allocate_subtab(big_tab, s, c)))
	{
		free_all(big_tab);
		return (NULL);
	}
	fill_subtab(big_tab, s, c);
	return (big_tab);
}
