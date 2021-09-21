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
