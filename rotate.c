#include "push_swap.h"

void	ra(t_list **stack_a, t_list **stack_b, int p)
{
	t_list	*tmp;
	t_list	*buff;

	if (!(*stack_a) || !((*stack_a)->next))
		return ;
	tmp = *stack_a;
	buff = (*stack_a)->next;
	while ((*stack_a)->next)			// looking for last node
		*stack_a = (*stack_a)->next; //increment until it ends
	(*stack_a)->next = tmp;			//the last node takes the first
	tmp = NULL;
	*stack_a = buff;
	if (p == 1)
		ft_putstr("ra\n");
}

void	rb(t_list **stack_a, t_list **stack_b, int p)
{
	t_list	*tmp;
	t_list	*buff;

	if (!(*stack_b) || !((*stack_b)->next))
		return ;
	tmp = *stack_b;
	buff = (*stack_b)->next;
	while ((*stack_b)->next)
		*stack_b = (*stack_b)->next;
	(*stack_b)->next = tmp;
	tmp = NULL;
	*stack_b = buff;
	if (p == 1)
		ft_putstr("rb\n");
}

void	rr(t_list **stack_a, t_list **stack_b, int p)
{
	ra(stack_a, stack_b, 0);
	rb(stack_a, stack_b, 0);
	if (p == 1)
		ft_putstr("rr\n");
}
