/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:23:29 by vlomakin          #+#    #+#             */
/*   Updated: 2023/07/25 13:45:43 by vlomakin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(char const *s, char c)
{
	int	words;
	int	counter;

	words = 0;
	counter = 0;
	while (*s)
	{
		if (*s != c && counter == 0)
		{
			counter = 1;
			words++;
		}
		else if (*s == c)
		{
			counter = 0;
		}
		s++;
	}
	return (words);
}

int	word_length(char const *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			s++;
			i++;
		}
		else
			return (i);
	}
	return (i);
}

char	**copy_words(char const *s, char c, int words, char **result)
{
	int	i;
	int	j;
	int	word_len;

	i = 0;
	j = 0;
	while (i < words && result)
	{
		while (s[j] && s[j] == c)
			j++;
		word_len = word_length(&s[j], c);
		result[i] = malloc(sizeof(char) * (word_len + 1));
		if (!result[i])
			return (NULL);
		ft_strlcpy(result[i], &s[j], word_len + 1);
		while (s[j] && s[j] != c)
			j++;
		i++;
	}
	result[i] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	result = (char **)malloc(sizeof(char *) * (words + 1));
	if (!result)
		return (NULL);
	return (copy_words(s, c, words, result));
}

// // int main()
// // {
// //     char **lines;
// //     lines = ft_split("lorem ipsum dolor sit amet,
// 		consectetur adipiscing elit. Sed non risus. Suspendisse", ' ');
// //     int i = 0;
// //     while (lines[i])
// // 	{
// //         printf("%s\n", lines[i]);
// //         i++;
// //     }
// // }