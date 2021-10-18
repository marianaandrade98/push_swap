/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandrade <mandrade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:36:14 by mandrade          #+#    #+#             */
/*   Updated: 2021/10/18 17:00:33 by mandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** looks for the minimum value and pushes to stack b
*/

void	push_min_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int	min;

	min = ft_dlst_min(*stack_a);
	while ((*stack_a)->data != min)
	{
		if ((*stack_a)->data != min && (*stack_a)->next->data != min)
			rra(stack_a, 1);
		else
			ra(stack_a, 1);
	}
	pb(stack_a, stack_b, 1);
}

/*
** it will grab the median of 'stack_a' between the first two limits
** of the stack 'limits' and add it to 'limits'.
** 			- it starts by creating a duplicated stack of 'stack_a' and sorting
** 		the dup, so it will be a sorted version of 'stack_a'
** 			- then, it will try to find the index in duplicate of the first element
**		of 'limits', the same happens to the second element.
**			- after that, it is possible to find the index of the median. The
**		calculations are: (max_i - min_i) / 2 + min_i
**			- the 'new' will then be the element whose index in duplicate is the
**		number in between max_i and min_i
**			- 'new' is added to 'limits' and 'limits' is sorted so that it contains
**		all the partitions of stack_a in order
*/

// void	get_new_limit(t_stack **limits, t_stack *stack, int status)
// {
// 	t_stack	*dup;
// 	int		min_i;
// 	int		max_i;
// 	int		new;

// 	dup = ft_dlst_duplicate(stack);
// 	ft_dlst_sort(&dup);
// 	if (status)
// 	{
// 		min_i = ft_dlst_find(dup, (*limits)->data);
// 		max_i = ft_dlst_find(dup, (*limits)->next->data);
// 		new = ft_dlst_get(dup, ((max_i - min_i) / 2 + min_i + 3));
// 	}
// 	else
// 		new = ft_dlst_get(dup, ft_dlst_size(dup) / 2);
// 	ft_dlstadd_front(limits, ft_dlst_new(new));
// 	ft_dlst_sort(limits);
// 	ft_dlst_clear(&dup);
// }

void	get_new_limit(t_stack **limits, t_stack *stack, int status)
{
	t_stack	*duplicate;
	int		min_idx;
	int		max_idx;
	int		new;

	duplicate = ft_dlst_duplicate(stack);
	ft_dlst_sort(&duplicate);
	if (status)
	{
		min_idx = ft_dlst_find(duplicate, (*limits)->data);
		max_idx = ft_dlst_find(duplicate, (*limits)->next->data);
		new = ft_dlst_get(duplicate, ((max_idx - min_idx) / 2 + min_idx + 3));
	}
	else
		new = ft_dlst_get(duplicate, ft_dlst_size(duplicate) / 2);
	ft_dlstadd_front(limits, ft_dlst_new(new));
	ft_dlst_sort(limits);
	ft_dlst_clear(&duplicate);
}

/*
** iterates stack_a, from the top and finds the first number with values between
** the first and the second number in 'limits'
**		- stack_a will be iterated in order to find the position of the first number
**			between 'limits'
**		- 'limits' will serve as the limits to find the number in 'stack_a'
** the function returns the extimated number or "ra" instructions necessary for the
** number found in stack_a to be on top.
*/

int	get_hold_first(t_stack *stack_a, t_stack *limits)
{
	int	first;
	int	max;
	int	min;

	min = limits->data;
	max = limits->next->data;
	first = 0;
	while (stack_a)
	{
		if (stack_a->data >= min && stack_a->data <= max)
			return (first);
		first++;
		stack_a = stack_a->next;
	}
	return (first);
}

/*
** helper function of merge_sort_to_a(). It will return the minimum number
** of srack_a that is not sorted, as the new limit.
*/

// int	get_next_value(t_stack *stack_a, t_stack **limits)
// {
// 	t_stack	*dup;
// 	int		pos;
// 	int		min;

// 	dup = ft_dlst_duplicate(stack_a);
// 	ft_dlst_sort(&dup);
// 	pos = ft_dlst_find(dup, (*limits)->next->data);
// 	min = ft_dlst_get(dup, pos);
// 	if (min == ft_dlst_last(dup)->data)
// 	{
// 		ft_dlst_clear(&dup);
// 		return (min);
// 	}
// 	else
// 		min = ft_dlst_get(dup, pos + 1);
// 	ft_dlst_clear(&dup);
// 	return (min);
// }

int	get_next_value(t_stack *stack_a, t_stack **limits)
{
	t_stack	*duplicate;
	int		position;
	int		minimum;

	duplicate = ft_dlst_duplicate(stack_a);
	ft_dlst_sort(&duplicate);
	position = ft_dlst_find(duplicate, (*limits)->next->data);
	minimum = ft_dlst_get(duplicate, position);
	if (minimum == ft_dlst_last(duplicate)->data)
	{
		ft_dlst_clear(&duplicate);
		return (minimum);
	}
	else
		minimum = ft_dlst_get(duplicate, position + 1);
	ft_dlst_clear(&duplicate);
	return (minimum);
}