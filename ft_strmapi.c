/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 12:50:41 by vlomakin          #+#    #+#             */
/*   Updated: 2023/07/16 16:29:23 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char*	str;

	i = 0;
	if (!s)
		return (NULL);
	if (!(str = (char *)malloc(sizeof(char) * (ft_strlen(s)) + 1)))
		return (NULL);
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

// #include <stdio.h>
// #include <stdlib.h>

// char	ft_charmap(unsigned int index, char c)
// {
// 	(void)index;
// 	if (c >= 'a' && c <= 'z')
// 	{
// 		c -= 32;
// 	}
// 	return (c);
// }
// int		main(void)
// {
// 	char *str = "Hello, World!";
// 	char *result = ft_strmapi(str, &ft_charmap);

// 	if (result)
// 	{
// 		printf("Original string: %s\n", str);
// 		printf("Mapped string  : %s\n", result);
// 		free(result);
// 	}
// 	else
// 	{
// 		printf("Error: Failed to allocate memory.\n");
// 	}

// 	return (0);
// }
