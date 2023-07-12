/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:23:29 by vlomakin          #+#    #+#             */
/*   Updated: 2023/07/12 17:55:31 by vlomakin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(char const *s, char c)
{
	int	i;
	int	counter;
	int	words;

	i = 0;
	words = 0;
	while(s[i] == c && s[i])
		i++;
	while (s[i])
	{
		if (s[i] != c && counter == 0)
		{
			counter = 1;
			words++;
		}
		else if (s[i] == c)
			counter = 0;
		i++;
	}	
	return(words);
}

int	word_len(char const *s, char c)
{
	int	i;
	
	i = 0;
	while (s[i])
	{
		if(s[i]!= c)
			i++;
		i++;
	}
	return(i);
}

char	**ft_split(char const *s, char c)
{
	char **h;
	int	i;
	
	i = 0;
	h = (char**)malloc(sizeof(char) * count_words(s, c) + 1);
	while(s[i] && s[i] == c)
		i++;
	while(s[i])
	{
		h = 
	}
	
}

int main()
{
	char s1[] = "*hfnsdjk*judfnjds**enfe*";
	printf("%d", count_words(s1, '*'));
	return(0);
}