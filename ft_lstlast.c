/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 10:53:16 by vlomakin          #+#    #+#             */
/*   Updated: 2023/07/25 15:01:51 by vlomakin         ###   ########.fr       */
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
//     t_list *elem1 = (t_list *)malloc(sizeof(t_list));
//     elem1->content = "Element 1";
//     elem1->next = NULL;

//     t_list *elem2 = (t_list *)malloc(sizeof(t_list));
//     elem2->content = "Element 2";
//     elem2->next = NULL;

//     t_list *elem3 = (t_list *)malloc(sizeof(t_list));
//     elem3->content = "Element 3";
//     elem3->next = NULL;

//     t_list *head = elem1;
//     elem1->next = elem2;
//     elem2->next = elem3;

//     t_list *last = ft_lstlast(head);

//     printf("Last element: %s\n", (char *)last->content);
// }