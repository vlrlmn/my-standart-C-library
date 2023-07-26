/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 14:57:51 by vlomakin          #+#    #+#             */
/*   Updated: 2023/07/25 11:22:35 by vlomakin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	unsigned char	h;

	str = (unsigned char *)b;
	h = (unsigned char)c;
	while (len--)
	{
		*str = h;
		str++;
	}
	return (b);
}

// int main()
// {
// 	unsigned char s1[] = "Hello";
// 	unsigned char*	str;

// 	str = ft_memset(s1, '%', 4);
// 	printf("%s", str);
// }