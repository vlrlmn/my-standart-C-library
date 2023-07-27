/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 10:56:58 by vlomakin          #+#    #+#             */
/*   Updated: 2023/07/26 19:23:00 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*a;

	if (!lst)
		return ;
	while (*lst)
	{
		a = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = a;
	}
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

// 	ft_lstclear(&(a->next), del);
	
// 	t_list *tmp = a;
// 	while(tmp)
// 	{
// 		printf("%s\n", (char*)tmp->content);
// 		tmp = tmp->next;
// 	}
// }

// #include <stdio.h>
// void del(void *a)
// {
//     printf("removed: %s\n", (char*)a);
//     return ;
// }

// int main()
// {
//     t_list *lst;
//     t_list *lst1;

//     lst = ft_lstnew("Word 1");
//     lst->next = ft_lstnew("word 2");
//     lst->next->next = ft_lstnew("word 3");
//     lst->next->next->next = ft_lstnew("word 4");

//     ft_lstclear(&(lst->next), del);
//     lst1 = lst;
//     while(lst)
//     {
//         printf("%s\n", (char*)lst->content);
//         lst = lst->next;
//     }
//     ft_lstdelone(lst1, del);
// }