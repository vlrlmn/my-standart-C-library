/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 12:48:53 by vlomakin          #+#    #+#             */
/*   Updated: 2023/07/21 12:27:45 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
int num_len(int n)
{
    int i;
    long long int h;

    i = 0;
    h = n; 
    if (h == 0)
    {
        return(1);
    }
    if (h < 0)
    {
        h *= -1;
        i++;
    }
    while(h > 0)
    {
        h /= 10;
        i++;
    }
    return(i);
}

char* make_str(int digits, long long int h, int flag)
{
    char    *str;

    str = (char*)malloc(sizeof(char) * (digits + 1));
    if (!str)
        return (NULL);
    str[digits] = '\0';
    while (digits--)
    {
        str[digits] = (h % 10) + '0';
		h /= 10;
    }
    if (flag)
        str[0] = '-';
    return (str);    
} 

char    *ft_itoa(int n)
{
    int digits;
    int flag;
    long long int h;

    h = n;
    flag = 0;
    digits = num_len(h);
    if (h < 0)
	{
		flag = 1;
		h = -h;
	}
    return make_str(digits, h , flag);
}

// int main()
// {
// 	int c = -2147483648LL;
// 	printf("%s", ft_itoa(c));
// }