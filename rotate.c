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
	if (!stack_a)
		return ;
	*stack_a = ft_dlst_first(*stack_a);
	(*stack_a)->next->prev = NULL;
	ft_dlstadd_back(stack_a, ft_dlst_new((*stack_a)->data));
	ft_dlst_remove(stack_a);
	*stack_a = ft_dlst_first(*stack_a);
	if (p == 1)
		ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack **stack_b, int p)
{
	if (!stack_b)
		return ;
	*stack_b = ft_dlst_first(*stack_b);
	(*stack_b)->next->prev = NULL;
	ft_dlstadd_back(stack_b, ft_dlst_new((*stack_b)->data));
	ft_dlst_remove(stack_b);
	*stack_b = ft_dlst_first(*stack_b);
	if (p == 1)
		ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack **stack_a, t_stack **stack_b, int p)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	if (p == 1)
		ft_putstr_fd("rr\n", 1);
}
