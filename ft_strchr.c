/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 18:43:19 by vlomakin          #+#    #+#             */
/*   Updated: 2023/07/10 17:21:10 by vlomakin         ###   ########.fr       */
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