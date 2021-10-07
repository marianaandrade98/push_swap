#include "push_swap.h"

static int	position_down(t_stack *stack, int median, int limit)
{
	int	pos;

	pos = 1;
	while (stack->next)
	{
		if (stack->data > median && stack->data < limit)
			break ;
		else
		{
			stack = stack->next;
			pos++;
		}
	}
	return (pos);
}

static int	position_up(t_stack *stack, int median, int limit)
{
	int	pos;

	pos = 1;
	stack = ft_dlst_last(stack);
	while (stack->prev)
	{
		if (stack->data > median && stack->data < limit)
			break ;
		else
		{
			stack = stack->prev;
			pos++;
		}
	}
	return (pos);
}

int	rotate_choice_2(t_stack *stack, int median, int limit)
{
	int	pos_down;
	int	pos_up;

	pos_down = position_down(stack, median, limit);
	pos_up = position_up(stack, median, limit);
	if (pos_up < pos_down)
		return (0);
	else
		return (1);
}
