/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstis_dup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandrade <mandrade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:52:57 by mandrade          #+#    #+#             */
/*   Updated: 2021/10/12 15:53:00 by mandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_lst.h"

/*
**  checks if there is a duplicate number
*/

int	ft_dlstis_dup(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack)
	{
		if (stack->data == stack->next->data)
			return (1);
		stack = stack->next;
	}
	return (0);
}
