#include "double_lst.h"

/*
**  takes us back to the first node
*/

t_stack	*ft_dlst_first(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->prev)
		stack = stack->prev;
	return (stack);
}
