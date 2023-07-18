/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 12:48:53 by vlomakin          #+#    #+#             */
/*   Updated: 2023/07/18 14:28:52 by lomakinaval      ###   ########.fr       */
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
        i = 1;
    else if (h < 0)
    {
        h *= -1;
        i++;
        while(h > 0)
        {
            h /= 10;
            i++;
        }
    }
    else if (h > 0)
    {
        while(h > 0)
        {
            h /= 10;
            i++;
        }
    }
    return(i);
}

char    *ft_itoa(int n)
{
    char    *str;
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
    if (!(str = (char*)malloc(sizeof(char) * (digits + 1))))
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

// int main()
// {
// 	int c = -2147483648LL;
// 	printf("%s", ft_itoa(c));
// }