#include "double_lst.h"

/*
**  give us size of stack
*/

int	ft_dlst_size(t_stack *stack)
{
	int	i;

	i = 1;
	if (!stack)
		return (0);
	while (stack->next)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}
