#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list *lst1;
    t_list *new;

    lst1 = (void*)0;
    while(lst)
    {
        new = ft_lstnew(f(lst->content));
        if(!new)
        {
            ft_lstclear(&lst1, del);
            return (lst1);
        }
        ft_lstadd_back(&lst1, new);
        lst = lst->next;
    }
    return (lst1);
}

// void *func(void *up_symbol)
// {
//     *(char *)up_symbol = 'T';
//     return(up_symbol);
// }

// void dele(void *a)
// {
//     return ;
// }

// int main()
// {
//     t_list *a;
//     t_list *b;

//     char w1[] = "word1";
//     char w2[] = "word2";
//     char w3[] = "word3";
    
//     a = ft_lstnew(w1);
//     a->next = ft_lstnew(w2);
//     a->next->next = ft_lstnew(w3);

//     t_list *tmp;

//     b = ft_lstmap(a, func, dele);
//     tmp = b;
//     while(tmp)
//     {
//         printf("%s\n", (char*)tmp->content);
//         tmp = tmp->next;
//     }

//     return 0;
// }
