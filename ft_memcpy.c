/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:09:40 by vlomakin          #+#    #+#             */
/*   Updated: 2023/07/25 11:22:39 by vlomakin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*p;
	unsigned char	*q;
	size_t			i;

	if (!dst && !src)
		return (NULL);
	p = (unsigned char *)dst;
	q = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		p[i] = q[i];
		i++;
	}
	return (dst);
}

// int main()
// {
// 	char src[10] = "Hello";
// 	char dst[10];
// 	ft_memcpy(dst, src, 3);
// 	printf("%s", dst);
// }