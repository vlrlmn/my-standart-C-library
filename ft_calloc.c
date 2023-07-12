/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:47:51 by vlomakin          #+#    #+#             */
/*   Updated: 2023/07/10 16:13:28 by vlomakin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;
	size_t	amount;

	amount = count * size;
	str = malloc(amount);
	if (str == NULL)
		return (NULL);
	ft_bzero(str, amount);
	return (str);
}

// int	main(void)
// {
// 	char	*str;

// 	str = ft_calloc(0, 5);
// 	if (str != NULL)
// 		printf("Success");
// }