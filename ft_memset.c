/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 14:57:51 by vlomakin          #+#    #+#             */
/*   Updated: 2023/07/04 13:04:42 by vlomakin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char* str;
	str = (unsigned char*)b;
	while (len--)
	{
		*str++ = c;
	}
	return (b);
}

// int main()
// {
// 	unsigned char s1[] = "Hello";
// 	printf("%s", ft_memset(s1, '%', 4));
// }