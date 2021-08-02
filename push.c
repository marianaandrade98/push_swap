#include "push_swap.h"

void	pa(t_list **stack_a, t_list **stack_b, int p)
{
	t_list	*temp;

	if (!(*stack_b))
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = *stack_a;
	*stack_a = temp;
	if (p == 1)
		ft_putstr("pa\n");
}

void	pb(t_list **stack_a, t_list **stack_b, int p)
{
	t_list	*temp;

	if (!(*stack_a))
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = *stack_b;
	*stack_b = temp;
	if (p == 1)
		ft_putstr("pb\n");
}
