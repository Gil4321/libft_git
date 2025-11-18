/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adghouai <adghouai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:26:53 by adghouai          #+#    #+#             */
/*   Updated: 2025/11/18 15:31:58 by adghouai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*char	function(unsigned int x, char c)
{
	c = c + x;
	return (c);
}*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			len;
	char			*str;
	size_t			i;

	i = 0;
	len = ft_strlen(s);
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	while (s[i])
	{
		str[i] = (*f)(i, (((char *)s)[i]));
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*int	main(void)
{
	char	*str;
	char	(*ptr)(unsigned int, char);

	ptr = &function;
	str = ft_strmapi("chaine", ptr);
	printf("%s", str);
}*/