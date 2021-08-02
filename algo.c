#include "push_swap.h"

void	sort_3(t_list **stack_a)
{
	int	botton;
	int	middle;
	int	top;

	botton = (int)(*stack_a)->next->next->content;
	middle = (int)(*stack_a)->next->content;
	top = (int)(*stack_a)->content;
	if (top > middle && middle < botton && botton > top)
	{
		sa(stack_a, 1);
	}
	else if (top > middle && middle > botton && botton < top)
	{
		sa(stack_a, 1);
		rra(stack_a, 1);
	}
	else if (top > middle && middle < botton && botton < top)
		ra(stack_a, 1);
	else if (top < middle && middle > botton && botton > top)
	{
		sa(stack_a, 1);
		ra(stack_a, 1);
	}
	else if (top < middle && middle > botton && botton < top)
		rra(stack_a, 1);
}
