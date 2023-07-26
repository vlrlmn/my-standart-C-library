/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 10:56:58 by vlomakin          #+#    #+#             */
/*   Updated: 2023/07/25 14:56:07 by vlomakin         ###   ########.fr       */
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