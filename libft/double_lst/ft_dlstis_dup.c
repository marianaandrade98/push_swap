#include "double_lst.h"

/*
**  checks if there is a duplicate number
*/

int	ft_dlstis_dup(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack)
	{
		if (stack->data == stack->next->data)
			return (1);
		stack = stack->next;
	}
	return (0);
}
