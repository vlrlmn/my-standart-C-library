/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:36:20 by vlomakin          #+#    #+#             */
/*   Updated: 2023/07/17 13:42:44 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
    size_t i = 0;

    if (dstsize == 0)
        return (ft_strlen(src));
        
    while (src[i] && i < dstsize - 1) {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    
    return (ft_strlen(src));
}

// int main()
// {
// 	char s1[] = "Hellooo";
// 	char s2[3];
// 	ft_strlcpy(s2, s1, sizeof(s2));
// 	printf("%s", s2);
// }