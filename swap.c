#include "push_swap.h"

void	sa(t_list **stack_a, int p)
{
	void	*tmp;

	if (!(*stack_a))
		return ;
	if ((*stack_a)->next)
	{
		tmp = (*stack_a)->content;
		(*stack_a)->content = (*stack_a)->next->content;
		(*stack_a)->next->content = tmp;
		if (p == 1)
			ft_putstr("sa\n");
	}
}

void	sb(t_list *stack_b, int p)
{
	void	*tmp;

	if (!stack_b)
		return ;
	if (stack_b->next)
	{
		tmp = stack_b->content;
		stack_b->content = stack_b->next->content;
		stack_b->next->content = tmp;
		if (p == 1)
			ft_putstr("sb\n");
	}
}

void	ss(t_list *stack_a, t_list *stack_b, int p)
{
	sa(&stack_a, 0);
	sb(stack_b, 0);
	if (p == 1)
			ft_putstr("ss\n");
}

