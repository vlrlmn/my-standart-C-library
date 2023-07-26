/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 10:58:14 by vlomakin          #+#    #+#             */
/*   Updated: 2023/07/25 15:39:03 by vlomakin         ###   ########.fr       */
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

// #include <stdio.h>

// void f(void *up_symbol)
// {
//     *((char*)up_symbol) = 'W';
// }

// int main()
// {
//     t_list *lst;
//     char word1[] = "word 1";
//     char word2[] = "word 2";
//     char word3[] = "word 3";
//     char word4[] = "word 4";

//     lst = ft_lstnew(word1);
//     lst->next = ft_lstnew(word2);
//     lst->next->next = ft_lstnew(word3);
//     lst->next->next->next = ft_lstnew(word4);

//     ft_lstiter(lst, f);
//     while(lst)
//     {
//         printf("%s\n", (char*)lst->content);
//         lst = lst->next;
//     }
// }