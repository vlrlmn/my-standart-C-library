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
//     b = ft_lstnew("Abcd");
//     printf("%p\n", b->content);
//     printf("%s\n", (char *)b->content);
// }
