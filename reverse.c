#include "push_swap.h"

void	rra(t_list **stack_a, int p)
{
	t_list	*tmp;
	t_list	*buff; //test this, it may not be necessary

	if (!(*stack_a))
		return ;
	tmp = *stack_a;
	buff = *stack_a;
	while (tmp->next)		//find last node of tmp
	{
		if (tmp->next->next)
			buff = buff->next;
		tmp = tmp->next;
	}
	buff->next = NULL;
	tmp->next = *stack_a; //organize everything in tmp
	*stack_a = tmp;		//puts everything in the stack
	if (p == 1)
		ft_putstr("rra\n");
}

void	rrb(t_list **stack_b, int p)
{
	t_list	*tmp;
	t_list	*buff;

	if (!(*stack_b))
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
	rra(stack_a, 0);
	rrb(stack_b, 0);
	if (p == 1)
		ft_putstr("rrr\n");
}
