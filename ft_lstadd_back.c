/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 10:55:23 by vlomakin          #+#    #+#             */
/*   Updated: 2023/07/26 18:57:16 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*new_ls;

	new_ls = *lst;
	if (!new_ls)
	{
		*lst = new;
		return ;
	}
	new_ls = ft_lstlast(*lst);
	new_ls->next = new;
}

// int main()
// {
// 	t_list *a;
// 	t_list *to_add;
// 	to_add = ft_lstnew("Old_first");
// 	to_add->next = ft_lstnew("Old_second");
// 	to_add->next->next = ft_lstnew("Old_third");

// 	a = ft_lstnew("Word 1");
// 	a->next = ft_lstnew("Word 2");
// 	a->next->next = ft_lstnew("I'll put that crap in the end");
	
// 	ft_lstadd_back(&to_add, a->next->next);
// 	t_list *tmp = to_add;

// 	while(tmp!= NULL)
// 	{
// 		printf("%s\n", (char*)tmp->content);
// 		tmp = tmp->next;
// 	}
// }