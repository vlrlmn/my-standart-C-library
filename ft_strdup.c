/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:30:54 by vlomakin          #+#    #+#             */
/*   Updated: 2023/07/12 11:47:09 by vlomakin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	unsigned char	*p;
	unsigned char	*q;

	p = (unsigned char*)dst;
	q = (unsigned char*)src;

	if (!p && !q)
		return (NULL);
	while (n--)
	{
		*p++ = *q++;
	}
	return (p);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char *new_str;

	len = ft_strlen(s1) + 1;

	new_str = (char *)malloc(sizeof(char) * len);
	if (!new_str)
		return (NULL);
	ft_memcpy(new_str, s1, len);
	return (new_str);
}

// int main()
// {
// 	char s1[] = "hello";
// 	printf("%s", ft_strdup(s1));
// }