/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:53:50 by vlomakin          #+#    #+#             */
/*   Updated: 2023/07/16 13:55:25 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

void ft_striteri(char *s, void(*f)(unsigned int, char*))
{
	unsigned int	i;
	
	i = 0;
	while(s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// void print_char(unsigned int index, char *c)
// {
// 	printf("Index: %u, Character: %c\n", index, *c);
// }

// int main()
// {
// 	char str[] = "Hello world";
// 	ft_striteri(str, print_char);
	
// 	return 0;
// }