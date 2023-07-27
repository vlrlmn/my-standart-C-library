/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 12:20:16 by vlomakin          #+#    #+#             */
/*   Updated: 2023/07/26 18:32:57 by lomakinaval      ###   ########.fr       */
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
// 	t_list *old_list = NULL;
// 	t_list *add;

// 	add = ft_lstnew("Word 1");
// 	add->next = ft_lstnew("Word 2");
// 	add->next->next = ft_lstnew("I'll put that in the beginning");

// 	ft_lstadd_front(&old_list, add->next->next);
// 	t_list *tmp = old_list;

// 	while(tmp != NULL)
// 	{
// 		printf("%s\n", (char*)tmp->content);
// 		tmp = tmp->next;
// 	}
// }