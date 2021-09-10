#include "push_swap.h"
#include "libft/libft.h"
/*
**	find the last node of the temp
**	organize everything in temp by linking again with the stack
**	puts the organized version in the stack
*/

static void	ft_rrotate(t_stack **stack)
{
	t_stack	*temp;

	if (!stack)
		return ;
	temp = ft_dlst_last(*stack);
	temp->prev->next = NULL;
	ft_dlstadd_front(stack, ft_dlst_new(temp->data));
	ft_dlst_remove(&temp);
}

void	ft_rrotate_rra(t_stack **stack)
{
	ft_putstr_fd("rra\n", 1);
	ft_rrotate(stack);
}

void	ft_rrotate_rrb(t_stack **stack)
{
	ft_putstr_fd("rrb\n", 1);
	ft_rrotate(stack);
}

void	ft_rrotate_rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_putstr_fd("rrr\n", 1);
	ft_rrotate(stack_a);
	ft_rrotate(stack_b);
}
