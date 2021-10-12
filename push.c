/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandrade <mandrade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:35:54 by mandrade          #+#    #+#             */
/*   Updated: 2021/10/12 15:35:55 by mandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **stack_a, t_stack **stack_b, int p)
{
	if (!stack_b)
		return ;
	ft_dlstadd_front(stack_a, ft_dlst_new((*stack_b)->data));
	ft_dlst_remove(stack_b);
	if (p == 1)
		ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack **stack_a, t_stack **stack_b, int p)
{
	if (!stack_a)
		return ;
	ft_dlstadd_front(stack_b, ft_dlst_new((*stack_a)->data));
	ft_dlst_remove(stack_a);
	if (p == 1)
		ft_putstr_fd("pb\n", 1);
}
