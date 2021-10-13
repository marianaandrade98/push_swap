#include "double_lst.h"

/*
**  give us the number of elements in stack
*/

int	ft_dlst_size(t_stack *stack)
{
	int	i;

	i = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}
