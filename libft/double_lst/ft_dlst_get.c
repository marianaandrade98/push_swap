
#include "double_lst.h"

/*
** returns the value of a position in stack if it exists.
** if the position is bigger than the size of the stack,
**     the function returns INT_MIN
*/

int	ft_dlst_get(t_stack *stack, int position)
{
	int	i;
	
	i = 0;
	while (stack)
	{
		if (i == position)
			return (stack->data);
		stack = stack->next;
		i++;
	}
	return (-2147483648);
}
