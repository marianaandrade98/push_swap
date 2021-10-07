#include "push_swap.h"

static void	pre_sort(t_stack **stack)
{
	int	temp;

	if (*stack)
	{
		while (ft_dlstis_sorted_ascend(*stack) != 1)
		{
			while ((*stack)->next)
			{
				if ((*stack)->data > (*stack)->next->data)
				{
					temp = (*stack)->data;
					(*stack)->data = (*stack)->next->data;
					(*stack)->next->data = temp;
				}
				*stack = (*stack)->next;
			}
			*stack = ft_dlst_first(*stack);
		}
	}
}

int	median_pos(t_stack *temp, int median)
{
	int	pos;

	pos = 0;
	while (temp->next)
	{
		if (temp->data == median)
			break ;
		else
		{
			temp = temp->next;
			pos++;
		}
	}
	return (pos);
}

t_stack	*builder(t_stack *stack)
{
	t_stack	*temp;

	temp = NULL;
	while (stack)
	{
		build_stack(stack->data, &temp);
		stack = stack->next;
	}
	pre_sort(&temp);
	return (temp);
}

int	ft_dlst_median(t_stack *stack)
{
	int		median;
	int		size;
	int		i;
	t_stack	*temp;

	i = 1;
	temp = NULL;
	temp = builder(stack);
	size = ft_dlst_size(stack);
	stack = ft_dlst_first(stack);
	while (i++ <= (size / 2))
		temp = temp->next;
	median = temp->data;
	ft_dlst_clear(&temp);
	return (median);
}

int	aux_median_check(t_stack *stack_a, int median)
{
	t_stack	*temp;
	int		aux_median;
	int		i;

	i = 0;
	temp = NULL;
	temp = builder(stack_a);
	while (temp->data != median)
	{
		temp = temp->next;
		i++;
	}
	i = i / 2;
	while (i-- > 0)
		temp = temp->next;
	aux_median = temp->data;
	temp = ft_dlst_last(temp);
	ft_dlst_clear(&temp);
	return (aux_median);
}
