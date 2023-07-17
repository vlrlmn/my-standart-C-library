/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 13:28:54 by vlomakin          #+#    #+#             */
/*   Updated: 2023/07/17 13:15:37 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memmove(void *dst, const void *src, size_t len)
{
    char *dst_ptr;
    const char *src_ptr;
    size_t i;

    if (!dst || !src)
        return (NULL);
	dst_ptr = (char *)dst;
	src_ptr = (const char *)src;
    if (dst_ptr < src_ptr)
    {
		ft_memcpy(dst_ptr, src_ptr, len);
    }
    else
    {
        i = len;
        while (i > 0)
        {
            dst_ptr[i - 1] = src_ptr[i - 1];
            i--;
        }
    }
    return (dst);
}

// int main()
// {
// 	char src[6] = "Hello";
// 	char dst[4];
// 	ft_memmove(dst, src, 4);
// 	printf("%s", dst);
// }