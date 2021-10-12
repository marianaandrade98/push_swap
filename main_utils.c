/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandrade <mandrade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:35:24 by mandrade          #+#    #+#             */
/*   Updated: 2021/10/12 15:35:25 by mandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Takes the string arguments from argv, convert them to int and
** adds them to the bach of stack_a.
** Checks if the arguments are numbers and if there are duplicates.
** It also checks the limits.
** If any of these cases happens, the program displays an error message
*/

void	build_stack(char **argv, t_stack **stack_a)
{
	int			i;
	long int	data;
	t_stack		*new_node;

	i = 0;
	while (argv[i])
	{

	}
}

/*
** it ends the program.
** 0 - in case of crash - ends the program with an error message
** 1 - in case of success - ends the program without any warning
**     and clear the stacks.
*/

void	exit_program(t_stack *stack_a, t_stack *stack_b, int status)
{
	if (stack_a)
		clear
	if (stack_b)
		clear
	if (!status)
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
