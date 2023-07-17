/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:37:50 by vlomakin          #+#    #+#             */
/*   Updated: 2023/07/17 13:45:13 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char *haystack_end;
	const char *h;
	const char *n;

	if (!*needle)
		return ((char *)haystack);
	haystack_end = haystack + len;
	while ((haystack < haystack_end) && *haystack)
	{
		h = haystack;
		n = needle;
		while ((*h == *n) && *n && (h < haystack_end))
		{
			n++;
			h++;
		}
		if (!*n)
			return ((char *)haystack);

		haystack++;
	}
	return (NULL);
}

// #include <string.h>
// int main()
// {
// 	char s1[] = "Heeeellloooo";
// 	char s2[] = "llo";
// 	printf("%s\n", ft_strnstr(s1, s2, 20));
// 	printf("%s", strnstr(s1, s2, 9));
// }