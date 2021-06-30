#include "push_swap.h"

void	pa(t_list **list_a, t_list **list_b, int p)
{
	t_list	*temp;

	if (!(*list_b))
		return ;
	temp = *list_b;
	*list_b = (*list_b)->next;
	temp->next = *list_a;
	*list_a = temp;
	if (p == 1)
		ft_putstr("pa\n");
	if (p == 2)
	{
		ft_putstr("Execute pa:\n\n");

	}
}

void	pa(t_list **list_a, t_list **list_b, int p)
{
	t_list	*temp;

	if (!(*list_a))
		return ;
	temp = *list_a;
	*list_a = (*list_a)->next;
	temp->next = *list_b;
	*list_b = temp;
	if (p == 1)
		ft_putstr("pb\n");
	if (p == 2)
	{
		ft_putstr("Execute pb:\n\n");
		
	}
}
