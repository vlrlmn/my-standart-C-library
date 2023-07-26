/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 12:20:16 by vlomakin          #+#    #+#             */
/*   Updated: 2023/07/25 14:53:53 by vlomakin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst)
		return ;
	new->next = *lst;
	*lst = new;
}

// int main()
// {
//     t_list *elem1 = (t_list *)malloc(sizeof(t_list));
//     elem1->content = "Element 1";
//     elem1->next = NULL;

//     t_list *elem2 = (t_list *)malloc(sizeof(t_list));
//     elem2->content = "Element 2";
//     elem2->next = NULL;

//     t_list *head = NULL;

//     ft_lstadd_front(&head, elem2);
//     ft_lstadd_front(&head, elem1);

//     t_list *current = head;
//     while (current != NULL)
//     {
//         printf("%s\n", (char *)current->content);
//         current = current->next;
//     }
// }