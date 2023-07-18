/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:23:29 by vlomakin          #+#    #+#             */
/*   Updated: 2023/07/18 13:43:48 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int count_words(char const *s, char c)
{
    int words;
    int counter;
    
    words = 0;
    counter = 0;
    while(*s)
    {
        if(*s != c && counter == 0)
        {
            counter = 1;
            words++;
        }
        else if(*s == c)
        {
            counter = 0;
        }
        s++;
    }
    return(words);
}

int word_length(char const *s, char c)
{
    int i;
    i = 0;
    while(*s)
    {
        if(*s != c)
        {
            s++;
            i++;
        }
        else
            return(i);
    }
    return(i);
}

char    **ft_split(char const *s, char c)
{
    int i;
    int j;
    char **result;
    int words;
    int word_len;

    i = 0;
    j = 0;
    words = count_words(s, c);
    if(!(result = (char**)malloc(sizeof(char*) * (words + 1))))
		return (NULL);
    while(i < words && result)
    {
        while(s[j] && s[j] == c)
            j++;
        word_len = word_length(&s[j], c);
        if(!(result[i] = malloc(sizeof(char) * (word_len + 1))))
			return (NULL);
        ft_strlcpy(result[i], &s[j], word_len + 1);
        result[i][word_len] = '\0';
        while(s[j] && s[j] != c)
            j++;
        i++;
    }
    result[i] = NULL;
    return(result);
}

// int main()
// {
//     char **lines;
	
//     lines = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse", ' ');
//     int i = 0;
//     while (lines[i]) 
// 	{
//         printf("%s\n", lines[i]);
//         i++;
//     }
// }