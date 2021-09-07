#include "push_swap.h"

/*
**	tmp takes the head of the stack, which give it access to the whole list
**	buff takes everything but the head 
**	looking for last node
**	increment until it ends
**	tmp cuts the next link
**	links the last node to the first
**	puts the other numbers first
**	ex:	stack : 1, 2 , 3 , 4
**	final stack :	2, 3 , 4 , 1
*/

void	ra(t_stack **stack_a, int p)
{
	t_stack	*tmp;
	t_stack	*buff;

	if (!(*stack_a))
		return ;
	tmp = *stack_a;
	buff = (*stack_a)->next; 
	while ((*stack_a)->next)
		*stack_a = (*stack_a)->next;
	tmp->next = NULL;
	(*stack_a)->next = tmp;
	*stack_a = buff;
	if (p == 1)
		ft_putstr("ra\n");
}

void	rb(t_stack **stack_b, int p)
{
	t_stack	*tmp;
	t_stack	*buff;

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

void	rr(t_stack **stack_a, t_stack **stack_b, int p)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	if (p == 1)
		ft_putstr("rr\n");
}
