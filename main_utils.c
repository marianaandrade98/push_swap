/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandrade <mandrade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:36:14 by mandrade          #+#    #+#             */
/*   Updated: 2021/10/14 17:07:06 by mandrade         ###   ########.fr       */
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
** it starts by creating a duplicated stack of 'stack_a' and sorting
** 		the dup, so it will be a sorted version of 'stack_a'
*/

void	get_new_limit(t_stack **limits, t_stack *stack, int status)
{
	t_stack	*dup;
	int		min_i;
	int		max_i;
	int		new;

	dup = ft_dlst_duplicate(stack);
	ft_dlst_sort(dup);
	if (status)
	{
		min_i = ft_dlst_find(dup, (*limits)->data);
		max_i = ft_dlst_find(dup, (*limits)->next->data);
		new = ft_dlst_get(dup, ((max_i - min_i) / 2 + min_i + 3));
	}
	else
		new = ft_dlst_get(dup, ft_dlst_size(dup) / 2);
	ft_dlstadd_front(limits, ft_dlst_new(new));
	ft_dlst_sort(limits);
	ft_dlst_clear(&dup);
}
