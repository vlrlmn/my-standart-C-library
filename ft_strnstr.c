/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:37:50 by vlomakin          #+#    #+#             */
/*   Updated: 2023/07/21 13:05:39 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strnstr(const char *haystack, const char* needle, size_t len)
{
	size_t i;
	size_t j;

	if (!*needle)
		return ((char *)haystack);
    if (!len)
		return((char *)NULL);
	i = 0;
	while (haystack[i] && i < len)
	{
		j = 0;
		while (needle[j] && haystack[i + j] && needle[j] == haystack[i + j] && i + j < len)
			j++;
		if(!needle[j])
			return ((char*)&haystack[i]);
		if (!haystack[i + j] || i + j == len)
			return((char *)NULL);
		i++;
	}
	return ((char*)NULL);
}

// #include <string.h>
// int main()
// {
// 	char s1[] = "Heeeellloooo";
// 	char s2[] = "llo";
// 	printf("%s\n", ft_strnstr(s1, s2, 20));
// 	printf("%s", strnstr(s1, s2, 9));
// }