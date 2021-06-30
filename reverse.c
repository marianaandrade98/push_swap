#include "push_swap.h"

void	rra(t_list **list_a, t_list **list_b, int p)
{
	t_list	*tmp;
	t_list	*buff;

	if (!(*list_a) || !((*list_a)->next))
		return ;
	tmp = *list_a;
	buff = *list_a;
	while (tmp->next)
	{
		if (tmp->next->next)
			buff = buff->next;
		tmp = tmp->next;
	}
	buff->next = NULL;
	tmp->next = *list_a;
	*list_a = tmp;
	if (p == 1)
		ft_putstr("rra\n");
	if (p == 2)
	{
		ft_putstr("Execute rra:\n\n");

	}
}

void	rrb(t_list **list_a, t_list **list_b, int p)
{
	t_list	*tmp;
	t_list	*buff;

	if (!(*list_b) || !((*list_b)->next))
		return ;
	tmp = *list_b;
	buff = *list_b;
	while (tmp->next)
	{
		if (tmp->next->next)
			buff = buff->next;
		tmp = tmp->next;
	}
	buff->next = NULL;
	tmp->next = *list_b;
	*list_b = tmp;
	if (p == 1)
		ft_putstr("rrb\n");
	if (p == 2)
	{
		ft_putstr("Execute rrb:\n\n");

	}
}

void	rrr(t_list **list_a, t_list **list_b, int p)
{
	rra(list_a, list_b, 0);
	rrb(list_a, list_b, 0);
	if (p == 1)
		ft_putstr("rrr\n");
	if (p == 2)
	{
		ft_putstr("Execute rrr:\n\n");

	}
}
