/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandrade <mandrade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:35:36 by mandrade          #+#    #+#             */
/*   Updated: 2021/10/12 15:35:37 by mandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack_a, int p)
{
	int	temp;

	stack_a = ft_dlst_first(stack_a);
	if (stack_a->next == NULL || !stack_a)
		return ;
	{
		temp = stack_a->next->data;
		stack_a->next->data = stack_a->data;
		stack_a->data = temp;
	}
	stack_a = ft_dlst_first(stack_a);
	if (p == 1)
		ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack *stack_b, int p)
{
	int	temp;

	stack_b = ft_dlst_first(stack_b);
	if (stack_b->next == NULL || !stack_b)
		return ;
	{
		temp = stack_b->next->data;
		stack_b->next->data = stack_b->data;
		stack_b->data = temp;
	}
	stack_b = ft_dlst_first(stack_b);
	if (p == 1)
		ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack *stack_a, t_stack *stack_b, int p)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
	if (p == 1)
		ft_putstr_fd("ss\n", 1);
}
