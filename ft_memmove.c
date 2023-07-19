/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 13:28:54 by vlomakin          #+#    #+#             */
/*   Updated: 2023/07/19 13:10:40 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memmove(void *dst, const void *src, size_t len)
{
    unsigned char *dst_ptr;
    unsigned char *src_ptr;
    size_t i;

    if (dst == NULL || src == NULL)
        return ((void*)-1);
	dst_ptr = (unsigned char *)dst;
	src_ptr = (unsigned char *)src;
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

int main()
{
	ft_memmove(NULL, NULL, 4);
}