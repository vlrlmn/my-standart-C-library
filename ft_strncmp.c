/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 20:09:20 by vlomakin          #+#    #+#             */
/*   Updated: 2023/07/25 13:36:28 by vlomakin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (n && *s1 && *s2)
	{
		if (*s1 != *s2)
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		s1++;
		s2++;
		n--;
	}
	if (n > 0)
		return (*(unsigned char *)s1 - *(unsigned char *)s2);
	return (0);
}

// int main()
// {
// 	char s1[] = "hhhhhh";
// 	char s2[] = "ahhhhh";
// 	printf("%d", ft_strncmp(s1, s2, 1));
// }