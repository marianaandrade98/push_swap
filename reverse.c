#include "push_swap.h"

/*
**	find the last node of the temp
**	organize everything in temp by linking again with the stack
**	puts the organized version in the stack
*/

void	rra(t_stack **stack_a, int p)
{
	t_stack	*temp;

	if (!stack_a)
		return ;
	temp = ft_dlst_last(*stack_a);
	temp->prev->next = NULL;
	ft_dlstadd_front(stack_a, ft_dlst_new(temp->data));
	ft_dlst_remove(&temp);
	if (p == 1)
		ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack **stack_b, int p)
{
	t_stack	*temp;

	if (!stack_b)
		return ;
	temp = ft_dlst_last(*stack_b);
	temp->prev->next = NULL;
	ft_dlstadd_front(stack_b, ft_dlst_new(temp->data));
	ft_dlst_remove(&temp);
	if (p == 1)
		ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack **stack_a, t_stack **stack_b, int p)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	if (p == 1)
		ft_putstr_fd("rrr\n", 1);
}
