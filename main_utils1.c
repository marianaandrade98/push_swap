/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandrade <mandrade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:01:18 by mandrade          #+#    #+#             */
/*   Updated: 2021/10/18 16:58:49 by mandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** takes a stack and counts its numbers in between the first two elements
** of 'limits'.
*/

int	count_in_between(t_stack *stack_a, t_stack *limits)
{
	t_stack	*duplicate;
	int		max_idx;
	int		min_idx;

	duplicate = ft_dlst_duplicate(stack_a);
	ft_dlst_sort(&duplicate);
	min_idx = ft_dlst_find(duplicate, limits->data);
	max_idx = ft_dlst_find(duplicate, limits->next->data);
	ft_dlst_clear(&duplicate);
	return (max_idx - min_idx + 1);
}

/*
** splits stack_a to stack_b the numbers whose limits are between the first two
** elements of the stack 'limits'.
*/

// void	split_a_to_b(t_stack **stack_a, t_stack **stack_b, t_stack *limits)
// {
// 	int	size;
// 	int	first;

// 	size = count_in_between(*stack_a, limits);
// 	while (ft_dlst_size(*stack_b) < size)
// 	{
// 		first = get_hold_first(*stack_a, limits);
// 		while (first--)
// 			ra(stack_a, 1);
// 		pb(stack_a, stack_b, 1);
// 	}
// }

void	split_a_to_b(t_stack **stack_a, t_stack **stack_b, t_stack *limits)
{
	int	size;
	int	first;

	size = count_in_between(*stack_a, limits);
	while (ft_dlst_size(*stack_b) < size)
	{
		first = get_hold_first(*stack_a, limits);
		while (first--)
			ra(stack_a, 1);
		pb(stack_a, stack_b, 1);
	}
}

/*
** Rotates stack_a until the sorted numbers are found at the bottom of the stack
** sorted in descending order.
*/

void	rotate_until_sorted(t_stack **stack_a, t_stack *limits)
{
	t_stack	*dup;
	int		num;
	int		i;

	dup = ft_dlst_duplicate(*stack_a);
	ft_dlstadd_front(&dup, ft_dlst_new(limits->data));
	ft_dlst_sort(&dup);
	num = ft_dlst_get(dup, ft_dlst_find(dup, limits->data) - 1);
	ft_dlst_clear(&dup);
	i = ft_dlst_find(*stack_a, num);
	if (num == -2147483648 || i == -2147483648)
		return ;
	if (i <= ft_dlst_size(*stack_a) / 2)
		while (ft_dlst_last(*stack_a)->data != num)
			ra(stack_a, 1);
	else
		while (ft_dlst_last(*stack_a)->data != num)
			rra(stack_a, 1);
}

/*
** takes stack_b and all its numbers above the second element of 'limits'
** are pushed back to stack_a.
*/

// void	merge_half_to_a(t_stack **stack_a, t_stack **stack_b, t_stack *limits)
// {
// 	get_new_limit(&limits, *stack_b, 0);
// 	while (ft_dlst_has_bigger(*stack_b, limits->next->data))
// 	{
// 		if ((*stack_b)->data == ft_dlst_min(*stack_b))
// 		{
// 			pa(stack_a, stack_b, 1);
// 			if ((*stack_b)->data != ft_dlst_min(*stack_b)
// 				&& (*stack_b)->data <= limits->next->data)
// 				rr(stack_a, stack_b, 1);
// 			else
// 				ra(stack_a, 1);
// 		}
// 		else if ((*stack_b)->data > limits->next->data)
// 			pa(stack_a, stack_b, 1);
// 		else
// 			rb(stack_b, 1);
// 	}
// }

void	merge_half_to_a(t_stack **stack_a, t_stack **stack_b, t_stack *limits)
{
	get_new_limit(&limits, *stack_b, 0);
	while (ft_dlst_has_bigger(*stack_b, limits->next->data))
	{
		if ((*stack_b)->data == ft_dlst_min(*stack_b))
		{
			pa(stack_a, stack_b, 1);
			if ((*stack_b)->data != ft_dlst_min(*stack_b)
				&& (*stack_b)->data <= limits->next->data)
				rr(stack_a, stack_b, 1);
			else
				ra(stack_a, 1);
		}
		else if ((*stack_b)->data > limits->next->data)
			pa(stack_a, stack_b, 1);
		else
			rb(stack_b, 1);
	}
}

/*
** merges the rest of stack_b in a sorted matter.
*/

// void	merge_sort_to_a(t_stack **stack_a, t_stack **stack_b, t_stack *limits)
// {
// 	t_stack	*dup;

// 	dup = ft_dlst_duplicate(*stack_b);
// 	ft_dlst_sort(&dup);
// 	while (ft_dlst_size(*stack_b))
// 	{
// 		if ((*stack_b)->data == dup->data)
// 		{
// 			pa(stack_a, stack_b, 1);
// 			dup = dup->next;
// 			if (ft_dlst_size(*stack_b) && (*stack_b)->data != dup->data
// 				&& (*stack_b)->data != ft_dlst_max(*stack_b))
// 				rr(stack_a, stack_b, 1);
// 			else
// 				ra(stack_a, 1);
// 		}
// 		else if ((*stack_b)->data == ft_dlst_max(*stack_b))
// 			pa(stack_a, stack_b, 1);
// 		else
// 			rb(stack_b, 1);
// 	}
// 	while (ft_dlst_last(*stack_a)->data != limits->next->data)
// 		ra(stack_a, 1);
// 	limits->next->data = get_next_value(*stack_a, &limits);
// 	ft_dlst_clear(&dup);
// }

void	merge_sort_to_a(t_stack **stack_a, t_stack **stack_b, t_stack *limits)
{
	t_stack	*duplicate;

	duplicate = ft_dlst_duplicate(*stack_b);
	ft_dlst_sort(&duplicate);
	while (ft_dlst_size(*stack_b))
	{
		if ((*stack_b)->data == duplicate->data)
		{
			pa(stack_a, stack_b, 1);
			duplicate = duplicate->next;
			 if (ft_dlst_size(*stack_b) && (*stack_b)->data != duplicate->data
				&& (*stack_b)->data != ft_dlst_max(*stack_b))
				rr(stack_a, stack_b, 1);
			else
				ra(stack_a, 1);
		}
		else if ((*stack_b)->data == ft_dlst_max(*stack_b))
			pa(stack_a, stack_b, 1);
		else
			rb(stack_b, 1);
	}
	while (ft_dlst_last(*stack_a)->data != limits->next->data)
		ra(stack_a, 1);
	limits->next->data = get_next_value(*stack_a, &limits);
	ft_dlst_clear(&duplicate);
}
