/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 10:53:16 by vlomakin          #+#    #+#             */
/*   Updated: 2023/07/26 18:42:22 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

// int main()
// {
// 	t_list *a;
// 	t_list *last;
// 	a = ft_lstnew("Word 1");
// 	a->next = ft_lstnew("Word 2");
// 	a->next->next = ft_lstnew("Word 3");
// 	a->next->next->next = ft_lstnew("Word 4");
// 	last = ft_lstlast(a);
// 	printf("%s", (char*)last->content);
// }