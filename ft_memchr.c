/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 12:42:14 by vlomakin          #+#    #+#             */
/*   Updated: 2023/07/07 19:05:35 by vlomakin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void *ft_memchr(const void *s, int c, size_t n)
// {
// 	while(n)
// 	{
// 		if (*s == (char*)c)
// 			return((char*)s);
// 		s++;
// 		n--;
// 	}
// 	return((char*)s);
// }

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return (&str[i]);
		i++;
	}
	return (0);
}

// int main()
// {
// 	char *src = "12345566758";
// 	char *ptr;
// 	ptr = ft_memchr(src, '2', 6);
// 	if(ptr)
// 		printf("found");
// 	else
// 		printf("Not found");
// }
