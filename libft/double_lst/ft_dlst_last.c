#include "double_lst.h"

/*
**  takes us to the last node
*/

t_stack	*ft_dlst_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}