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
	int 	*stack;
	int		i;
	int 	size;
	t_list	*head;

	head = *stack_a;
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
	stack_a = &head;
	// printf("count = %d \n", (int)(*head).content);
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
	// printf("count = %d \n", (int)(*stack_a)->content);
	return (stack[size / 2]);
}

// void	stackA_to_stackB(t_list **stack_a, t_list **stack_b)
// {
// 	int		middle;
// 	t_list	*head;

// 	head = *stack_a;
// 	middle = middle_numb(stack_a);
// 	while (*stack_a)
// 	{
// 		while ((int)(*stack_a)->content < middle)
// 			pb(stack_a, stack_b, 1);
// 	}
// 	printf("count = %d \n", (int)(*stack_a)->content);
// 	stack_a = &head;
// }

int	verify_to_send(t_list **stack_a)
{
	int		middle;
	int 	count;
	t_list	*head;

	head = *stack_a;
	count = 0;
	middle = middle_numb(stack_a);
	stack_a = &head;
	while (*stack_a)
	{
		printf("here\n");
		if ((int)(*stack_a)->content < middle)
			return (count);
		*stack_a = (*stack_a)->next;
		count++;
	}
	// stack_a = &head;
	// printf("count = %d \n", (int)(*head).content);
	// printf("count = %d \n", (int)(*stack_a)->content);
	return (-1);
}

void	verify_pos(t_list **stack_a, t_list **stack_b)
{
	int	n;
	int	middle;
	t_list	*head;

	head = *stack_a;
	n = verify_to_send(stack_a);
	stack_a = &head;
	middle = ft_lstsize(*stack_a) / 2;
	stack_a = &head;
	while (n > 0)
	{
		printf("here pos\n");
		while ((int)(*stack_a)->content < middle)
			pb(stack_a, stack_b, 1);
		if (n < middle)
			rra(stack_a, 1);
		else
			ra(stack_a, 1);
		// while ((int)(*stack_a)->content < middle)
		// 	pb(stack_a, stack_b, 1);
	}
}
