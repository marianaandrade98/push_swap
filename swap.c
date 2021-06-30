#include "push_swap.h"

void	sa(t_list *stack_a, t_list *stack_b, int p)
{
	if (!stack_a)
		return ;
	if (stack_a->next)
	{
		ft_swap(&stack_a->content, &stack_a->next->content);
		if (p == 1)
			ft_putstr("sa\n");
	}
}

void	sb(t_list *stack_a, t_list *stack_b, int p)
{
	if (!stack_b)
		return ;
	if (stack_b->next)
	{
		ft_swap(&stack_b->content, &stack_b->next->content);
		if (p == 1)
			ft_putstr("sb\n");
	}
}

void	ss(t_list *stack_a, t_list *stack_b, int p)
{
	sa(stack_a, stack_b, 0);
	sb(stack_a, stack_b, 0);
	if (p == 1)
			ft_putstr("ss\n");
}
