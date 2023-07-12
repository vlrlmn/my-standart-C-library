/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 13:28:54 by vlomakin          #+#    #+#             */
/*   Updated: 2023/07/04 19:52:37 by vlomakin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char* p;
	unsigned char* q;
	unsigned char* temp;
	int i;

	p = (unsigned char*)dst;
	q = (unsigned char*)src;
	
	i = 0;
	while(i > len)
		temp[i] = q[i];
		i++;

	while(len--)
		*p++ = *q++;
	return(p);
}

// int main()
// {
// 	char src[10] = "Hello";
// 	char dst[3];
// 	ft_memmove(dst, src, 5);
// 	printf("%s", dst);
// }