/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 10:58:14 by vlomakin          #+#    #+#             */
/*   Updated: 2023/07/26 20:00:28 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

// void func(void *up_symbol)
// {
// 	*(char*)up_symbol = '-';
// }
// int main()
// {
// 	t_list *a;
// 	char w1[] = "word1";
// 	char w2[] = "word2";
// 	char w3[] = "word3";
// 	a = ft_lstnew(w1);
// 	a->next = ft_lstnew(w2);
// 	a->next->next = ft_lstnew(w3);
// 	ft_lstiter(a, func);
// 	while(a)
// 	{
// 		printf("%s\n", (char*)a->content);
// 		a = a->next;
// 	}
// }