#include "push_swap.h"

int	pos_check(t_stack *stack_a, int value)
{
	t_stack	*temp;
	int		pos;

	temp = NULL;
	pos = 0;
	temp = builder(stack_a);
	while (temp->next)
	{
		if (temp->data == value)
			break ;
		else
		{
			temp = temp->next;
			pos++;
		}
	}
	temp = ft_dlst_last(temp);
	ft_dlst_clear(&temp);
	return (pos);
}



void	sort_b_start(t_stack **stack_a, int min)
{
	int	choice;
	int	size;

	size = ft_dlst_size(*stack_a);
	choice = rotate_choice_limits(*stack_a, size, min);
	while ((*stack_a)->data != min)
	{
		if (choice == 1)
			ra(stack_a, 1);
		else
			rra(stack_a, 1);
	}
}

void	sort_b_500(t_stack **stack_b, t_stack **stack_a, int min)
{
	int	size;
	int	max;

	sort_b_start(stack_a, min);
	while (*stack_b)
	{
		size = ft_dlst_size(*stack_b);
		max = ft_dlst_max(*stack_b);
		if ((*stack_b)->data == max)
			pa(stack_a, stack_b, 1);
		else
		{
			if (rotate_choice_limits(*stack_b, size, max) == 1)
				rb(stack_b, 1);
			else
				rrb(stack_b, 1);
		}
	}
}


void	presort_b_500(t_stack **stack_b, t_stack **stack_a, int median)
{
	int	median_b;
	int	size;

	size = ft_dlst_size(*stack_a);
	median_b = ft_dlst_median(*stack_b);
	if ((*stack_b)->next)
	{
		if ((*stack_b)->data < median_b)
		{
			if ((*stack_a)->data < median)
				rr(stack_a, stack_b, 1);
			else
				rb(stack_b, 1);
		}
	}
	if ((*stack_b)->next && (*stack_b)->data > (*stack_b)->next->data)
		sb(*stack_b, 1);
}