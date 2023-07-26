/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 10:56:14 by vlomakin          #+#    #+#             */
/*   Updated: 2023/07/25 14:57:44 by vlomakin         ###   ########.fr       */
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

//     ft_lstdelone((lst->next), del);
//     lst1 = lst;
//     while(lst)
//     {
//         printf("%s\n", (char*)lst->content);
//         lst = lst->next;
//     }
//     ft_lstdelone(lst1, del);
// }
