#include "push_swap.h"

void	rra(t_list **stack_a, t_list **stack_b, int p)
{
	t_list	*tmp;
	t_list	*buff;

	if (!(*stack_a) || !((*stack_a)->next))
		return ;
	tmp = *stack_a;
	buff = *stack_a;
	while (tmp->next)
	{
		if (tmp->next->next)
			buff = buff->next;
		tmp = tmp->next;
	}
	buff->next = NULL;
	tmp->next = *stack_a;
	*stack_a = tmp;
	if (p == 1)
		ft_putstr("rra\n");
}

void	rrb(t_list **stack_a, t_list **stack_b, int p)
{
	t_list	*tmp;
	t_list	*buff;

	if (!(*stack_b) || !((*stack_b)->next))
		return ;
	tmp = *stack_b;
	buff = *stack_b;
	while (tmp->next)
	{
		if (tmp->next->next)
			buff = buff->next;
		tmp = tmp->next;
	}
	buff->next = NULL;
	tmp->next = *stack_b;
	*stack_b = tmp;
	if (p == 1)
		ft_putstr("rrb\n");
}

void	rrr(t_list **stack_a, t_list **stack_b, int p)
{
	rra(stack_a, stack_b, 0);
	rrb(stack_a, stack_b, 0);
	if (p == 1)
		ft_putstr("rrr\n");
}
