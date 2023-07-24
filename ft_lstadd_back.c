#include "libft.h"

void ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list *new_ls;

    new_ls = *lst;
    if(!new_ls)
    {
        *lst = new;
        return ;
    }
    new_ls = ft_lstlast(*lst);
    new_ls->next = new;
}

// int main()
// {
//     t_list *elem1 = (t_list *)malloc(sizeof(t_list));
//     elem1->content = "Element 1";
//     elem1->next = NULL;

//     t_list *elem2 = (t_list *)malloc(sizeof(t_list));
//     elem2->content = "Element 2";
//     elem2->next = NULL;

//     t_list *elem3 = (t_list *)malloc(sizeof(t_list));
//     elem3->content = "Element 3";
//     elem3->next = NULL;

//     t_list *head = elem1;
//     elem1->next = elem2;

//     ft_lstadd_back(&head, elem3);

//     t_list *current = head;
 
//     printf("%s\n", (char *)current->content);
// }