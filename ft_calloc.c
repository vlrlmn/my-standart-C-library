/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:47:51 by vlomakin          #+#    #+#             */
/*   Updated: 2023/07/14 13:08:09 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;
	size_t	amount;

	amount = count * size;
	if (!(str = malloc(amount)))
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