#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*l_new;

	if (!(l_new = malloc(sizeof(t_list))))
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
