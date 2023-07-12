/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 20:09:20 by vlomakin          #+#    #+#             */
/*   Updated: 2023/07/05 12:42:00 by vlomakin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while(n != 0)
	{
		if(*s1 != *s2)
			return(*(unsigned char*)s1 - *(unsigned char*)s2);
		n--;
	}
	return(0);
}

// int main()
// {
// 	char s1[] = "abdjs";
// 	char s2[] = "Affbhfri";
// 	printf("%d", ft_strncmp(s1, s2, 1));
// }