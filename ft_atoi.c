/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 14:44:42 by vlomakin          #+#    #+#             */
/*   Updated: 2023/07/26 16:16:28 by vlomakin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"

#include <stdio.h>

int	ft_atoi(const char *str)
{
	int			i;
	int			flag;
	long long	result;

	i = 0;
	flag = 1;
	result = 0;
	while (str[i] == ' ' || ((9 <= str[i]) && (str[i] <= 13)))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		flag = -1;
		i++;
	}
	while (str[i] && ('0' <= str[i]) && (str[i] <= '9'))
	{
		if (flag == 1 && result * 10 < result)
			return (-1);
		if (flag == -1 && result * 10 < result)
			return (0);
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (flag * result);
}

// #include <stdlib.h>

// int main()
// {
// 	char *s = "1234";
// 	printf("%d \n ", ft_atoi(s));
// 	printf("%d \n ", atoi(s));
// }