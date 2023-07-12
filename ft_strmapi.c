/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 12:50:41 by vlomakin          #+#    #+#             */
/*   Updated: 2023/07/12 14:53:37 by vlomakin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int	i;
	int	len;
	char	h;
	
	i = 0;
	len = ft_strlen(s) - 1;
	h = (char)malloc(sizeof(char) * len + 1);
	if(!h)
		return(NULL);
	while(s[i])
	{
		h = f(i, s[i]);
		i++;
	}
	h ='\0';
	return(h);
}
char f(unsigned int i, char s)
{
	while(i > 0)
	{
		printf("%c\n", s);
	}
	return(0);
}

// int main()
// {
// 	int i;
// 	i = 5; 
// 	char s[] = "asdhfjfkvvvcfk";
// 	ft_strmapi(s, f);
// }