#include "push_swap.h"

void	sa(t_stack **stack_a, int p)
{
	int	*tmp;

	if (!(*stack_a))
		return ;
	if ((*stack_a)->next)
	{
		tmp = (*stack_a)->data;
		(*stack_a)->data = (*stack_a)->next->data;
		(*stack_a)->next->data = tmp;
		if (p == 1)
			ft_putstr("sa\n");
	}
}

void	sb(t_stack *stack_b, int p)
{
	int	*tmp;

	if (!stack_b)
		return ;
	if (stack_b->next)
	{
		tmp = stack_b->data;
		stack_b->data = stack_b->next->data;
		stack_b->next->data = tmp;
		if (p == 1)
			ft_putstr("sb\n");
	}
}

void	ss(t_stack *stack_a, t_stack *stack_b, int p)
{
	sa(&stack_a, 0);
	sb(stack_b, 0);
	if (p == 1)
			ft_putstr("ss\n");
}

