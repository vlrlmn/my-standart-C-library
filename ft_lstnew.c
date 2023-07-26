/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 12:03:28 by vlomakin          #+#    #+#             */
/*   Updated: 2023/07/25 11:22:50 by vlomakin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*l_new;

	l_new = malloc(sizeof(t_list));
	if (!l_new)
		return (NULL);
	l_new->content = content;
	l_new->next = NULL;
	return (l_new);
}

// int		main(void)
// {
//     t_list	*b;
//     b = ft_lstnew("Haha");
//     printf("%p\n", b->content);
//     printf("%s\n", (char *)b->content);
// }
