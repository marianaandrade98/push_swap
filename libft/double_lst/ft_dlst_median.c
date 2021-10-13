#include "double_lst.h"

int	ft_dlst_median(t_stack *stack)
{
	t_stack	*dup;
	int		half;

	half = ft_dlst_size(stack) / 2;
	dup = ft_dlst_duplicate(stack);
	ft_dlst_sort(&dup);
	return (ft_dlst_get(dup, half - 1));
}
