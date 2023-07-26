/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:47:51 by vlomakin          #+#    #+#             */
/*   Updated: 2023/07/25 13:20:46 by vlomakin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	amount;

	if (count && INT_MAX / count < size)
	{
		return (NULL);
	}
	amount = count * size;
	ptr = malloc(amount);
	if (!ptr)
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