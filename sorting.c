#include "push_swap.h"

void	sorting(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	*stack_b = NULL;
	size = ft_dlst_size(*stack_a);
	if (ft_dlstis_sorted_ascend(*stack_a) == 0)
	{
		if (size <= 3)
			algo_small(stack_a);
	}
}

void	algo_small(t_stack **stack)
{
	int	max;
	int	min;
	int	sorted;

	max = ft_dlst_max(*stack);
	min = ft_dlst_min(*stack);
	*stack = ft_dlst_first(*stack);
	sorted = 0;
	while (sorted != 1)
	{
		if ((*stack)->data == max)
			ra(stack, 1);
		if ((*stack)->data > (*stack)->next->data)
			sa(*stack, 1);
		if ((*stack)->data != min)
			rra(stack, 1);
		if (ft_dlstis_sorted_ascend(*stack) == 1)
			break ;
		else if ((*stack)->data == min)
			rra(stack, 1);
		sorted = ft_dlstis_sorted_ascend(*stack);
	}
}