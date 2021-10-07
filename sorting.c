#include "push_swap.h"

void	sorting(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = ft_dlst_size(*stack_a);
	if (ft_dlstis_sorted_ascend(*stack_a) == 0)
	{
		if (size <= 3)
			algo_3(stack_a);
		else if (size <= 5)
			algo_5(stack_a, stack_b);
		else
			algo_500(stack_a, stack_b);
	}
}

void	algo_3(t_stack **stack)
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

void	algo_5(t_stack **stack_a, t_stack **stack_b)
{
	int	min;
	int	sorted;
	int	i;

	sorted = 0;
	i = 0;
	while (i < 2)
	{
		min = ft_dlst_min(*stack_a);
		*stack_a = ft_dlst_first(*stack_a);
		if ((*stack_a)->data == min)
		{
			pb(stack_a, stack_b, 1);
			i++;
		}
		else if (is_down_middle(*stack_a, min) == 1)
			ra(stack_a, 1);
		else
			rra(stack_a, 1);
	}
	algo_3(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b, 1);
}

void	algo_500(t_stack **stack_a, t_stack **stack_b)
{
	int	min;
	int	count;

	count = 0;
	min = 0;
	min = part_1(stack_a, stack_b);
	min = part_2(stack_a, stack_b, min);
	min = part_3(stack_a, stack_b, min);
	printf("after part 3\n");
	part_4(stack_a, stack_b, min);
}
