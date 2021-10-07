#include "push_swap.h"

int	part_1(t_stack **stack_a, t_stack **stack_b)
{
	int	median;
	int	aux_median;
	int	min;

	median = ft_dlst_median(*stack_a);
	aux_median = aux_median_check(*stack_a, median);
	part_1_cont(stack_a, stack_b, aux_median, median);
	min = ft_dlst_min(*stack_b);
	
	//continue
}

void	part_1_cont(t_stack **stack_a, t_stack **stack_b, int aux_median,
			int median)
{
	int	stop;
	int	comp_val;

	if (ft_dlst_size(*stack_a) % 4 != 0)
		comp_val = 0;
	else
		comp_val = 1;
	stop = pos_check(*stack_a, aux_median) - pos_check(*stack_a, median);
	while (stop > comp_val)
	{
		if ((*stack_a)->data > aux_median)
		{
			pb(stack_a, stack_b, 1);
			presort_b_500(stack_b, stack_a, median);
			stop--;
		}
		else
		{
			if (rotate_choice(*stack_a, aux_median) == 1)
				ra(stack_a, 1);
			else
				rra(stack_a, 1);
		}
	}
}
