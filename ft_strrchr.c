/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 19:33:00 by vlomakin          #+#    #+#             */
/*   Updated: 2023/07/07 13:29:28 by vlomakin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	counter;

	counter = ft_strlen(s) - 1;
	while (s[counter])
	{
		if (s[counter] == c)
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