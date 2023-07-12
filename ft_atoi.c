/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 14:44:42 by vlomakin          #+#    #+#             */
/*   Updated: 2023/07/12 17:45:03 by vlomakin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_flag(const char *str)
{
	int	i;
	int	flag;

	i = 0;
	if (str[i] == '-' && ft_isdigit(str[i + 1]) == 1)
	{
		flag = -1;
	}
	else if (ft_isdigit(str[i]) == 1)
	{
		flag = 1;
	}
	return (flag);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	flag;
	int	res;

	i = 0;
	flag = ft_flag(str);
	if (str[i] == '-')
		i++;
	while (str[i] && ft_isdigit(str[i]) == 1)
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * flag);
}

int main()
{
	char S[] = "-10000";
	printf("%d", ft_atoi(S));
}