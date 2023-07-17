/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 18:43:19 by vlomakin          #+#    #+#             */
/*   Updated: 2023/07/16 13:34:18 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strchr(const char *s, int c)
{
	while(s)
	{
		if(*s == c)
			return ((char*)s);
		else if(*s == '\0')
			return(NULL);
		s++;
	}
	return(0);
}

// int main()
// {
// 	char s[] = "Hello";
// 	char c = 'l';
// 	printf("%s", ft_strchr(s, c));
// }