#include "libft.h"

int ft_lstsize(t_list *lst)
{
    int i;

    i = 0;
    while(lst)
    {
        i++;
        if(lst->next)
            lst = lst->next;
        else
            return (i);
    }
    return(i);
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
//     elem2->next = elem3;

//     int size = ft_lstsize(head);
//     printf("%d\n", size);
// }