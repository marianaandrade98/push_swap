#include "double_lst.h"

void	ft_dlst_print(t_stack *stack)
{
	if (!stack)
		return ;
	stack = ft_dlst_first(stack);
	while (stack)
	{
		ft_putnbr_fd(stack->data, 1);
		if (stack->next)
			ft_putstr_fd(", ", 1);
		else
			ft_putstr_fd("\n", 1);
		stack = stack->next;
	}
}
