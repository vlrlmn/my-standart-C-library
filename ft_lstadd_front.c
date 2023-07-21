#include "libft.h"

void ft_lstadd_front(t_list **lst, t_list *new)
{
    if (!lst)
        return ;
    new->next = *lst;
    *lst = new;
}

// int main()
// {
//     t_list *elem1 = (t_list *)malloc(sizeof(t_list));
//     elem1->content = "Element 1";
//     elem1->next = NULL;

//     t_list *elem2 = (t_list *)malloc(sizeof(t_list));
//     elem2->content = "Element 2";
//     elem2->next = NULL;

//     // указатель на голову списка
//     t_list *head = NULL;

//     // Добавляем элементы в начало списка
//     ft_lstadd_front(&head, elem2);
//     ft_lstadd_front(&head, elem1);

//     // Проверяем, что элементы добавлены корректно
//     t_list *current = head;
//     while (current != NULL)
//     {
//         printf("%s\n", (char *)current->content);
//         current = current->next;
//     }
// }