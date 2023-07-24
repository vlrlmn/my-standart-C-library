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

// #include "libft.h"

// void del(void *content)
// {
//     free(content);
// }

// void *f(void *up_symbol)
// {
//     char *new_str = ft_strdup((char *)up_symbol);
//     if (new_str)
//     {
//         new_str[0] = 'W';
//     }
//     return new_str;
// }

// int main()
// {
//     t_list *lst;
//     t_list *a;
//     char word1[] = "word 1";
//     char word2[] = "word 2";
//     char word3[] = "word 3";
//     char word4[] = "word 4";

//     lst = ft_lstnew(ft_strdup(word1));
//     lst->next = ft_lstnew(ft_strdup(word2));
//     lst->next->next = ft_lstnew(ft_strdup(word3));
//     lst->next->next->next = ft_lstnew(ft_strdup(word4));

//     a = ft_lstmap(lst, f, del);

//     printf("Original list:\n");
//     t_list *iter = lst;
//     while(iter)
//     {
//         printf("%s\n", (char*)iter->content);
//         iter = iter->next;
//     }

//     printf("\nModified list:\n");
//     iter = a;
//     while(iter)
//     {
//         printf("%s\n", (char*)iter->content);
//         iter = iter->next;
//     }
//     ft_lstclear(&lst, del);
//     ft_lstclear(&a, del);

//     return 0;
// }
