/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:37:50 by vlomakin          #+#    #+#             */
/*   Updated: 2023/07/07 14:50:17 by vlomakin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char *	haystack_end;
	const char *h;
	const char *n;

	haystack_end = haystack + len;
	if (!*needle)
		return ((char *) haystack);
	while (haystack < haystack_end && *haystack)
	{
		h = haystack;
		n = needle;
		while (haystack < haystack_end && *h && *n && *h == *n)
		{
			n++;
			h++;
		}
		if (!*n)
		{
			return ((char *) haystack);
		}
		haystack++;
	}
	return (0);
}

// #include <string.h>
// int main()
// {
// 	char s1[] = "Heeeellloooo";
// 	char s2[] = "llo";
// 	printf("%s\n", ft_strnstr(s1, s2, 20));
// 	printf("%s", strnstr(s1, s2, 9));
// }