#include "push_swap.h"

void	sa(t_stack *stack_a, int p)
{
	int	tmp;

	stack_a = ft_dlst_first(stack_a);
	if (!stack_a)
		return ;
	if (stack_a->next)
	{
		tmp = stack_a->data;
		stack_a->data = stack_a->next->data;
		stack_a->next->data = tmp;
		if (p == 1)
			ft_putstr("sa\n");
	}
	stack_a = ft_dlst_first(stack_a);
}

void	sb(t_stack *stack_b, int p)
{
	int	tmp;

	stack_b = ft_dlst_first(stack_b);
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
	stack_b = ft_dlst_first(stack_b);
}

void	ss(t_stack *stack_a, t_stack *stack_b, int p)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
	if (p == 1)
			ft_putstr("ss\n");
}

