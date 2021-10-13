/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandrade <mandrade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:01:18 by mandrade          #+#    #+#             */
/*   Updated: 2021/10/13 17:10:43 by mandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** takes a stack and counts its numbers in between the first two elements
** of 'limits'
*/

int	count_in_between(t_stack *stack_a, t_stack *limits)
{
	t_stack	*dup;
	int	max_i;
	int	min_i;
	
	dup = ft_dlst_duplicate(stack_a);
	ft_dlst_sort(&dup);
	min_i = ft_dlst_find(dup, limits->data);
	max_i = ft_dlst_find(dup, limits->next->data);
	ft_dlst_clear(&dup);
	return (max_i - min_i + 1);
}
