/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 10:56:14 by vlomakin          #+#    #+#             */
/*   Updated: 2023/07/26 19:22:17 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

// void del(void *a)
// {
// 	return ;
// }

// int main()
// {
// 	t_list *a;

// 	a = ft_lstnew("W1");
// 	a->next = ft_lstnew("W2");
// 	a->next->next = ft_lstnew("W3");

// 	t_list *to_delete = a->next;
// 	a->next = a->next->next;
// 	ft_lstdelone(to_delete, del);
	
// 	t_list *tmp = a;
// 	while(tmp)
// 	{
// 		printf("%s\n", (char*)tmp->content);
// 		tmp = tmp->next;
// 	}
// }