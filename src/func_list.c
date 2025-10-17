#include "../includes/push_swap.h"

int lst_size(t_list *list)
{
    int     i;
    t_list  *temp;

    i = 0;
    temp = list;
    while (temp != NULL)
    {
        i++;
        temp = temp->next;
    }
    return (i);
}

void	ft_lst_add_back(t_list **a, t_list *new_node)
{
	t_list	*last;

	if (a == NULL || new_node == NULL)
		return ;
	if (*a == NULL)
	{
		*a = new_node;
		return ;
	}
	last = *a;
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
}