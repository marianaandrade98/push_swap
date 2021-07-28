#include "push_swap.h"

void	sort_3(t_list **stack_a)
{
	if (*stack_a > (*stack_a)->next && (*stack_a)->next < (*stack_a)->next->next) //case 1
		sa(stack_a, 1);
	else if (*stack_a > (*stack_a)->next && (*stack_a)->next > (*stack_a)->next->next) //case 2
	{
		sa(stack_a, 1);
		rra(stack_a, 1);
	}
	else if (*stack_a > (*stack_a)->next && (*stack_a)->next->next < *stack_a)  //case 3
		ra(stack_a, 1);
	else if (*stack_a < (*stack_a)->next && (*stack_a)->next->next > *stack_a)   //case 4
	{
		sa(stack_a, 1);
		ra(stack_a, 1);
	}
	else if (*stack_a < (*stack_a)->next && (*stack_a)->next > (*stack_a)->next->next) //case 5
		rra(stack_a, 1);
}
