/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 20:09:20 by vlomakin          #+#    #+#             */
/*   Updated: 2023/09/25 15:22:05 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (n-- && *s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	if (n == SIZE_MAX)
		return (0);
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

// int	ft_strncmp(const char *s1, const char *s2, size_t n)
// {
// 	if (n == 0)
// 		return (0);
// 	while (n && *s1 && *s2)
// 	{
// 		if (*s1 != *s2)
// 			return (*(unsigned char *)s1 - *(unsigned char *)s2);
// 		s1++;
// 		s2++;
// 		n--;
// 	}
// 	if (n > 0)
// 		return (*(unsigned char *)s1 - *(unsigned char *)s2);
// 	return (0);
// }
