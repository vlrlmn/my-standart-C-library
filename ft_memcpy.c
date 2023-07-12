/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:09:40 by vlomakin          #+#    #+#             */
/*   Updated: 2023/07/10 16:13:46 by vlomakin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	unsigned char	*p;
	unsigned char	*q;

	p = (unsigned char *)dst;
	q = (unsigned char *)src;

	if (!p && !q)
		return (NULL);
	while (n--)
	{
		*p++ = *q++;
	}
	return (p);
}

// int main()
// {
// 	char src[10] = "Hello";
// 	char dst[10];
// 	ft_memcpy(dst, src, 3);
// 	printf("%s", dst);
// }