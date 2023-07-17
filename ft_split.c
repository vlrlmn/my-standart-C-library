/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:23:29 by vlomakin          #+#    #+#             */
/*   Updated: 2023/07/17 17:55:27 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
int words_count(char const *s, char c)
{
	int i;
	int counter;
	int words;

	i = 0;
	counter = 0;
	words = 0;
	if (s[0] != c)
		words++;
	while (s[i])
	{
		if (s[i] != c && counter == 0)
		{
			counter = 1;
			words++;
		}
		else if (s[i] == c)
		{
			counter = 0;
		}
		i++;
	}
	if (s[i - 1] == c)
		words--;
	return (words);
}

int ft_word_len(char const *s, char c)
{
	int len;

	len = 0;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

char **ft_allocate_memory(int total_words)
{
	char **result;

	if (!(result = (char **)malloc(sizeof(char *) * (total_words + 1))))
		return (NULL);
	return (result);
}

char **ft_split_strings(char const *s, char c, char **result, int total_words)
{
	int word_len;
	int i;
	int j;

	i = 0;
	j = 0;
	while (total_words && i < total_words)
	{
		while (s[j] == c)
			j++;
		word_len = ft_word_len(&s[j], c);
		if (!(result[i] = (char *)malloc(sizeof(char) * (word_len + 1))))
			return (NULL);
		ft_strlcpy(result[i], &s[j], word_len + 1);
		j += word_len;
		i++;
	}
	result[i] = NULL;
	return (result);
}

char **ft_split(char const *s, char c)
{
	char **result;
	int total_words;

	if (!s)
		return NULL;
	total_words = words_count(s, c);
	if (total_words == 0)
	{
		if (!(result = ft_allocate_memory(0)))
			return NULL;
		result[0] = NULL;
		return (result);
	}
	if (!(result = ft_allocate_memory(total_words)))
		return NULL;
	return (ft_split_strings(s, c, result, total_words));
}


// int main()
// {
// 	char c[] ="*******I***am****/*a*good***person**u*";
//     char n = '*';
//     char **lines;
	
//     lines = ft_split(c, n);
//     int i = 0;
//     while (lines[i]) 
// 	{
//         printf("%s\n", lines[i]);
//         i++;
//     }
// }