/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 12:48:53 by vlomakin          #+#    #+#             */
/*   Updated: 2023/07/17 19:13:29 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_itoa(int n)
{
    char    *str;
    int     digits;
    int     number;
    int     neg_flag;
    char    ip;
 
    digits = 0;
    neg_flag = 0;
    if (n < 0)
    {
        n = -1 * n;
        neg_flag = 1;
    }
    number = n;
    while(number > 0)
    {
        number = number/10;
        digits++;
    }
    if (neg_flag)
        digits = digits + 1;
    str = (char*)malloc(sizeof(char)*(digits + 1));
    str[digits + 1] = '\0';
    number = n;
    while (number)
    {
        ip = number % 10 + '0';
        str[digits - 1] = ip;
        digits--;
        number = number/10;
    }
    if (neg_flag)
        str[0] = '-';
    return (str);
}

// int main()
// {
// 	int c = -1444;
// 	printf("%s", ft_itoa(c));
// }