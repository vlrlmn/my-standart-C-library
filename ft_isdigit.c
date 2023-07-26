/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 12:29:05 by vlomakin          #+#    #+#             */
/*   Updated: 2023/07/25 11:31:54 by vlomakin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

// int main()
// {
// 	int c;
// 	c = 'F';
// 	if(ft_isdigit(c) == 1)
// 		printf("is digit");
// 	else
// 		printf("not digit");
// }