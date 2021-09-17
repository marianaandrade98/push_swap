#include "double_lst.h"

/*
**  create new node in the beginning of the stack
*/

void	ft_dlstadd_front(t_stack **stack, t_stack *new_node)
{
	t_stack	*temp;

	temp = *stack;
	if (temp)
	{
		new_node->next = temp;
		temp->prev = new_node;
	}
	*stack = new_node;
}
