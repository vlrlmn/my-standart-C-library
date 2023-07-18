/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:47:51 by vlomakin          #+#    #+#             */
/*   Updated: 2023/07/18 19:20:52 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t amount;

	if (count != 0 && INT_MAX / count < size) {
		return (NULL);
    }
	amount = count * size;
	if (!(ptr = malloc(amount)))
		return (NULL);
	ft_bzero(ptr, amount);
	return (ptr);
}

// int	main(void)
// {
// 	char	*str;

// 	str = ft_calloc(-5, 0);
// 	if (str != NULL)
// 		printf("Success");
// }