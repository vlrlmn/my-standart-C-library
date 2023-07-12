/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 11:39:45 by vlomakin          #+#    #+#             */
/*   Updated: 2023/07/10 12:32:13 by vlomakin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	new_len;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	new_len = ft_strlen(s1) + ft_strlen(s2);
	new_str = (char *)malloc(sizeof(char) * new_len + 1);
	if (!new_str)
		return (NULL);
	if (!s1 && !s2)
		return (NULL);
	while (s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		new_str [i] = s2[j];
		j++;
		i++;
	}
	new_str [i] = '\0';
	return (new_str);
}

// int main()
// {
// 	char s1[] = "Hello";
// 	char s2[]= " world";
// 	printf("%s", ft_strjoin(s1, s2));
// }