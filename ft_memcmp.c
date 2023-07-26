/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:17:35 by vlomakin          #+#    #+#             */
/*   Updated: 2023/07/25 13:36:38 by vlomakin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p;
	unsigned char	*q;

	p = (unsigned char *)s1;
	q = (unsigned char *)s2;
	while (n--)
	{
		if (*p != *q)
			return (*p - *q);
		p++;
		q++;
	}
	return (0);
}

// int main()
// {
// 	char s1[] = "hhhhhh";
// 	char s2[] = "ahhhhh";

// 	printf("%d", ft_memcmp(s1, s2, 10));
// }