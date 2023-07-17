/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:30:54 by vlomakin          #+#    #+#             */
/*   Updated: 2023/07/16 13:42:13 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char *new_str;

	len = ft_strlen(s1);

	if (!(new_str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_memcpy(new_str, s1, len);
	*(new_str + len) = '\0';
	return (new_str);
}

// int main()
// {
// 	char s1[] = "hello";
// 	printf("%s", ft_strdup(s1));
// }