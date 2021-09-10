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

static void	ft_rotate(t_stack **stack)
{
	if (!stack)
		return ;
	*stack = ft_dlst_first(*stack);
	(*stack)->next->prev = NULL;
	ft_dlstadd_back(stack, ft_dlst_new((*stack)->data));
	ft_dlst_remove(stack);
	*stack = ft_dlst_first(*stack);
}

void	ft_rotate_ra(t_stack **stack_a)
{
	ft_putstr_fd("ra", 1);
	ft_putstr_fd("\n", 1);
	ft_rotate(stack_a);
}

void	ft_rotate_rb(t_stack **stack_b)
{
	ft_putstr_fd("rb", 1);
	ft_putstr_fd("\n", 1);
	ft_rotate(stack_b);
}

void	ft_rotate_rr(t_stack **stack_a, t_stack **stack_b)
{
	ft_putstr_fd("rr", 1);
	ft_putstr_fd("\n", 1);
	ft_rotate(stack_a);
	ft_rotate(stack_b);
}
