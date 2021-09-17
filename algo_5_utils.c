#include "push_swap.h"

static int	position_min(t_stack *stack, int min)
{
	int	pos;

	pos = 1;
	while (stack->next)
	{
		if (stack->data == min)
			break ;
		else
		{
			stack = stack->next;
			pos++;
		}
	}
	return (pos);
}

int	is_down_middle(t_stack *stack, int min)
{
	int	pos;
	int	size;

	size = ft_dlst_size(stack);
	pos = position_min(stack, min);
	if (pos > size / 2)
		return (0);
	else
		return (1);
}
