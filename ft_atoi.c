/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 14:44:42 by vlomakin          #+#    #+#             */
/*   Updated: 2023/07/17 14:18:43 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (flag * result);
}

// int main()
// {
// 	char S[] = "ф2147483648";
// 	printf("%d", ft_atoi(S));
// }