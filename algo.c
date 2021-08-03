#include "push_swap.h"

void	sort_3(t_list **stack_a)
{
	int	bottom;
	int	middle;
	int	top;

	bottom = (int)(*stack_a)->next->next->content;
	middle = (int)(*stack_a)->next->content;
	top = (int)(*stack_a)->content;
	if (top > middle && middle < bottom && bottom > top)
	{
		sa(stack_a, 1);
	}
	else if (top > middle && middle > bottom && bottom < top)
	{
		sa(stack_a, 1);
		rra(stack_a, 1);
	}
	else if (top > middle && middle < bottom && bottom < top)
		ra(stack_a, 1);
	else if (top < middle && middle > bottom && bottom > top)
	{
		sa(stack_a, 1);
		ra(stack_a, 1);
	}
	else if (top < middle && middle > bottom && bottom < top)
		rra(stack_a, 1);
}

/*
**	moves stack A to an array
**	sorts the array
** returns the middle
*/

int	middle_numb(t_list **stack_a)
{
	int *stack;
	int	i;
	int size;

	i = 0;
	size = ft_lstsize(*stack_a);
	stack = malloc(size);
	if (!stack)
		return (0);
	while (*stack_a)
	{
		stack[i++] = (int)(*stack_a)->content;
		*stack_a = (*stack_a)->next;
	}
	i = 0;
	while (stack[i])
	{
		if (stack[i] > stack[i + 1])
		{
			ft_swap(&stack[i], &stack[i + 1]);
			i = 0;
		}
		i++;
	}
	return (stack[size / 2]);
}

void	stackA_to_stackB(t_list **stack_a, t_list **stack_b)
{
	int		middle;
	t_list	*head;

	head = *stack_a;
	middle = middle_numb(&stack_a);
	while ((int)(*stack_a)->content < middle)
	{
		pb(stack_a, stack_b, 1);
		
	}
}

int	verify_to_send(t_list **stack_a)
{
	int		middle;
	int 	count;

	count = 0;
	middle = middle_numb(&stack_a);
	while (*stack_a)
	{
		if ((int)(*stack_a)->content < middle)
			return (count);
		*stack_a = (*stack_a)->next;
		count++;
	}
	return (-1);
}

void	verify_pos(t_list **stack_a, t_list **stack_b)
{
	int	n;
	int	middle;

	n = to_send(&stack_a);
	middle = ft_lstsize(*stack_a) / 2;
	while (n > 0)
	{
		n = to_send(&stack_a);
		while (*stack_a < middle)
			pb(&stack_a, &stack_b, 1);
		if (n < middle)
			rra(&stack_a, 1);
		else
			ra(&stack_a, 1);
		while (*stack_a < middle)
			pb(&stack_a, &stack_b, 1);
	}
}
