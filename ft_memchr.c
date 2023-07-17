/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 12:42:14 by vlomakin          #+#    #+#             */
/*   Updated: 2023/07/14 13:26:29 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	h;

	h = (unsigned char)c;
	str = (unsigned char *)s;
	while (n--)
	{
		if (*str == h)
			return (str);
		str++;
	}
	return (0);
}

// int main()
// {
// 	char *src = "12345566758";
// 	char *ptr;
// 	ptr = ft_memchr(src, '6', 3);
// 	if(ptr)
// 		printf("found");
// 	else
// 		printf("Not found");
// }
