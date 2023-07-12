/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:51:07 by vlomakin          #+#    #+#             */
/*   Updated: 2023/07/04 19:35:31 by vlomakin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char * restrict dst, const char * restrict src, size_t dstsize)
{
	int dest_len;
	char* p;
	char* q;
	int i;

	i = 0;
	p = (char*)dst;
	q = (char*)src;
	dest_len = ft_strlen(p);

	while(p != '\0' && q != '\0')
	{
		p[dest_len + i] = q[i];
		i++;
	}
	p[dest_len + i] = '\0';
	return(0);
}

// int main()
// {
// 	char s1[] = "Hello ";
// 	char s2[] = " everyone";
// 	ft_strlcat(s1, s2, ft_strlen(s1));
// 	printf("%s", s1);
// }