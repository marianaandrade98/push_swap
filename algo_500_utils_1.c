#include "push_swap.h"

int	pos_check(t_stack *stack_a, int value)
{
	t_stack	*temp;
	int		pos;

	temp = NULL;
	pos = 0;
	temp = builder(stack_a);
	while (temp->next)
	{
		if (temp->data == value)
			break ;
		else
		{
			temp = temp->next;
			pos++;
		}
	}
	temp = ft_dlst_last(temp);
	ft_dlst_clear(&temp);
	return (pos);
}
