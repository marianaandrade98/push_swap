#include "double_lst.h"

void	ft_dlst_clear(t_stack **stack)
{
	if (!*stack)
		return ;
	while (*stack)
		ft_dlst_remove(stack);
}
