/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandrade <mandrade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:34:49 by mandrade          #+#    #+#             */
/*   Updated: 2021/10/18 19:18:56 by mandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		exit(1);
	stack_a = 0;
	stack_b = 0;
	build_stack(&argv[1], &stack_a);
	if (!ft_dlstis_sorted(stack_a))
		sorting(&stack_a, &stack_b);

	// printf("stack A\n");
	// while (stack_a)
	// {
	// 	printf("%d, \n", stack_a->data);
	// 	stack_a = stack_a->next;
	// }
	// printf("stack B\n");
	// while (stack_b)
	// {
	// 	printf("%d, \n", stack_b->data);
	// 	stack_b = stack_b->next;
	// }
	exit_program(stack_a, stack_a, 1);
	
	return (0);
}

/*
** it selects the type of sorting algorithm based in size of stack_a
*/

void	sorting(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*limits;
	int	max;
	int	min;

	max = ft_dlst_max(*stack_a);
	min = ft_dlst_min(*stack_a);
	if (ft_dlst_size(*stack_a) <= 3)
		sort_3(stack_a);
	else if (ft_dlst_size(*stack_a) <= 5)
		sort_5(stack_a, stack_b);
	else
	{
		limits = ft_dlst_new(min);
		ft_dlstadd_back(&limits, ft_dlst_new(max));
		sort_500(stack_a, stack_b, &limits, 0);
	}
}

/*
** - if the second element of stack_a corresponds to the maximum valu
**		of the stack, and if the first one isn't the minimum value, we
**		only need to reverse rotate the stack. ex: 2 3 1
**
** - if the first element of the stack corresponds to the minimum value
**		and if the second one isn't the maximum value, we reverse the stack
**		ex: 3 1 2
**
** - if none happens, we swap the first two elements, either to sort it or
**		to reverse rotate or rotate after. ex: 3 2 1
*/

void	sort_3(t_stack **stack_a)
{
	int	max;
	int	min;

	max = ft_dlst_max(*stack_a);
	min = ft_dlst_min(*stack_a);
	while (!ft_dlstis_sorted(*stack_a))
	{
		if ((*stack_a)->data != min
			&& (*stack_a)->next->data == max)
			rra(stack_a, 1);
		else if ((*stack_a)->data == max
			&& (*stack_a)->next->data == min)
			ra(stack_a, 1);
		else
			sa(*stack_a, 1);
	}
}

/*
** pushes one or two smallest numbers of stack_a to stack_b
** once stack_a contains only 3 numbers we call the sort_3 function
** in the end the function pushes the stack_b's numbers back to stack_a
*/

void	sort_5(t_stack **stack_a, t_stack **stack_b)
{
	while (ft_dlst_size(*stack_a) > 3)
		push_min_to_b(stack_a, stack_b);
	sort_3(stack_a);
	while (ft_dlst_size(*stack_b))
		pa(stack_a, stack_b, 1);
}

/*
** the algorithm is separated in two different phases: the split phase and
** the merge phase.
**
** Split phase: is focused on pushing to stack_b the number in between a
**				certain chunk. These phase ends when all the numbers of chunk
**				are in stack_b.
**				ex:		100 random numbers from 1 to 100.
**						1st chunk: numbers from 1 to 50 in stack_b.
**						2nd chunk: numbers from 50 to 100 in stack_a.
**
** Then it will choose between:
** - Merge Back Phase: occurs if stack_b's size is too big for the Merge Sort
**						Phase. So half of the values of stack_b will go back to
**						stack_a - specifically values that are bigger than the median
**						value of stack_b. This will happen while at the same time
**						trying to sort what's possible back into stack_a.
** - Merge Sort Phase: occurs if stack_b's ready for sorting back into stack_a - has
**						a few amount of numbers which makes it possible for them
**						to go back sorted into stack_a.
*/

void	sort_500(t_stack **stack_a, t_stack **stack_b,
		t_stack **limits, int i)
{
	if (ft_dlst_size(*limits) == 1)
	{
		ft_dlst_clear(limits);
		return ;
	}
	if (ft_dlst_size(*limits) == 2 && count_in_between(*stack_a, *limits) >= MAX_SIZE)
		get_new_limit(limits, *stack_a, 1);
	if (!ft_dlst_size(*stack_b))
	{
		split_a_to_b(stack_a, stack_b, *limits);
		rotate_until_sorted(stack_a, *limits);
	}
	if (ft_dlst_size(*stack_b) >= MAX_SIZE)
		merge_half_to_a(stack_a, stack_b, *limits);
	else
	{
		merge_sort_to_a(stack_a, stack_b, *limits);
		ft_dlst_remove(limits);
	}
	sort_500(stack_a, stack_b, limits, ++i);
}
