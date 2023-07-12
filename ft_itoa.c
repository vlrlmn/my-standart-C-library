/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 12:48:53 by vlomakin          #+#    #+#             */
/*   Updated: 2023/07/12 19:00:51 by vlomakin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	rev_str(char *str)
{
	int i;
	char new_str;
	
	i = ft_strlen(str) - 1;
	while(str[i])
	{
		new_str = str[i];
		i--;
	}
	return(new_str);
}

char	*ft_itoa(int n)
{
	int x = 34;
	int	len;
	char	*str;
	int	i;
	char	n;
	
	len = ft_strlen(n);
	i = 0;
	str = malloc(len + 1);
	while (len > 0)
	{
		x /= 10;
		x %= 10;
		char n = x % 10; // 4
		str[i++] = '0' + n;
		len--;
	}
	n = rev_str(str);
}

int main()
{
	int c = 26373;
	printf("%s", ft_itoa(c));
}