/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 12:33:25 by vlomakin          #+#    #+#             */
/*   Updated: 2023/07/17 17:07:57 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int	str_begin;
	int	str_end;
	char	*new_str;

	str_begin = 0;
	str_end = ft_strlen(s1) - 1;
	if (!s1 || !set)
		return (NULL);
	while(ft_strchr(set, s1[str_begin]) && str_begin <= str_end)
		str_begin++;
	if(str_begin > str_end)
		return (ft_strdup(""));
	while(ft_strchr(set, s1[str_end]) && str_end >= 0)
		str_end--;
	if (!(new_str = (char *)malloc(sizeof(char) * (str_end - str_begin + 2))))
		return (NULL);
	ft_strlcpy(new_str, &s1[str_begin], str_end - str_begin + 2);
	return(new_str);
}

// int main()
// {
// 	char s[] = "jdfijfgmjfigknf";
// 	char set[] = "jdf";
// 	printf("%s", ft_strtrim(s, set));
// } 