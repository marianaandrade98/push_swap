#include "double_lst.h"

int     ft_dlstis_sorted_ascend(t_stack *stack)
{
	if (!stack)
		return (1);
	stack = ft_dlst_first(stack);
	while (stack->next)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int     ft_dlstis_sorted_descend(t_stack *stack)
{
	if (!stack)
		return (1);
	stack = ft_dlst_first(stack);
	while (stack->next)
	{
		if (stack->data < stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}
