/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 10:51:47 by vlomakin          #+#    #+#             */
/*   Updated: 2023/07/26 18:33:19 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		if (lst->next)
			lst = lst->next;
		else
			return (i);
	}
	return (i);
}

// int main()
// {
// 	t_list *a;
// 	int size;
// 	a = ft_lstnew("Word 1");
// 	a->next = ft_lstnew("Word 2");
// 	a->next->next = ft_lstnew("Word 3");
// 	size = ft_lstsize(a);
// 	printf("list size is: %d", size);
// }