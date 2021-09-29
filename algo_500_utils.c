#include "push_swap.h"

int	part_1(t_stack **stack_a, t_stack **stack_b)
{
	int	median;
	int	aux_median;
	int	min;

	median = ft_dlst_median(*stack_a);
	aux_median = aux_median_check(*stack_a, median);
	
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
	stop = 
}
