#include "push_swap.h"

void	ra(t_list **list_a, t_list **list_b, int p)
{
	t_list	*tmp;
	t_list	*buff;

	if (!(*list_a) || !((*list_a)->next))
		return ;
	tmp = *list_a;
	buff = (*list_a)->next;
	while ((*list_a)->next)			// looking for last node
		*list_a = (*list_a)->next; //increment until it ends
	(*list_a)->next = tmp;			//the last node takes the first
	tmp = NULL;
	*list_a = buff;
	if (p == 1)
		ft_putstr("ra\n");
	if (p == 2)
	{
		ft_putstr("Execute ra:\n\n");

	}
}

void	rb(t_list **list_a, t_list **list_b, int p)
{
	t_list	*tmp;
	t_list	*buff;

	if (!(*list_b) || !((*list_b)->next))
		return ;
	tmp = *list_b;
	buff = (*list_b)->next;
	while ((*list_b)->next)
		*list_b = (*list_b)->next;
	(*list_b)->next = tmp;
	tmp = NULL;
	*list_b = buff;
	if (p == 1)
		ft_putstr("rb\n");
	if (p == 2)
	{
		ft_putstr("Execute rb:\n\n");

	}
}

void	rr(t_list **list_a, t_list **list_b, int p)
{
	ra(list_a, list_b, 0);
	rb(list_a, list_b, 0);
	if (p == 1)
		ft_putstr("rr\n");
	if (p == 2)
	{
		ft_putstr("Execute rr:\n\n");

	}
}
