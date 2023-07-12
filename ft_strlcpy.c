/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:36:20 by vlomakin          #+#    #+#             */
/*   Updated: 2023/07/12 16:37:20 by vlomakin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char * restrict dst, const char * restrict src, size_t dstsize)
{
	unsigned char*	p;
	unsigned char*	q;

	p = (unsigned char*)dst;
	q = (unsigned char*)src;

	while(dstsize--)
		*p++ = *q++;
	return (0);
}

// int main()
// {
// 	char s1[] = "Hellooo";
// 	char s2[3];
// 	ft_strlcpy(s2, s1, 3);
// 	printf("%s", s2);
// }