/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 19:33:00 by vlomakin          #+#    #+#             */
/*   Updated: 2023/07/25 11:21:41 by vlomakin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	counter;

	counter = ft_strlen(s);
	while (counter >= 0)
	{
		if (s[counter] == (unsigned char)c)
			return ((char *)s + counter);
		counter--;
	}
	return (0);
}

// int main()
// {
// 	char s[] = "abcdeafg";
// 	char c = 'a';
// 	printf("%s", ft_strrchr(s, c));
// }