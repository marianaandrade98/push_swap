/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandrade <mandrade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 06:37:34 by mandrade          #+#    #+#             */
/*   Updated: 2021/10/20 06:49:42 by mandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** The main() function will prototype and initialize the two stacks of the
** project - 'stack_a' and 'stack_b'; fill in 'stack_a' with the move_to_stack()
** function; get the instructions from the user - get_instructions(); execute
** those instructions - call_instruction() function; and then exit the
** program - exit_checker().
**
*/

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_list	*instructions;

	if (argc == 1)
		exit(1);
	stack_a = 0;
	stack_b = 0;
	instructions = 0;
	build_stack(&argv[1], &stack_a);
	get_instructions(&stack_a, &instructions);
	call_instruction(&stack_a, &stack_b, instructions);
	if (ft_dlstis_sorted(stack_a) && !stack_b)
		exit_checker(stack_a, stack_b, &instructions, 2);
	exit_checker(stack_a, stack_b, &instructions, 1);
	return (0);
}

/*
** it will read a line from STDIN and validate it.
** The get_instructions() will read several lines from STDIN and store them - if
** valid - in instructions (t_list * structure).
**
*/

void	get_instructions(t_stack **stack_a, t_list **instructions)
{
	char	*line;
	t_list	*new_node;

	while (get_next_line(STDIN_FILENO, &line))
	{
		if (!(!ft_strcmp("sa", line) || !ft_strcmp("sb", line)
				|| !ft_strcmp("ss", line) || !ft_strcmp("pa", line)
				|| !ft_strcmp("pb", line) || !ft_strcmp("ra", line)
				|| !ft_strcmp("rb", line) || !ft_strcmp("rr", line)
				|| !ft_strcmp("rra", line) || !ft_strcmp("rrb", line)
				|| !ft_strcmp("rrr", line)))
		{
			free(line);
			exit_checker(*stack_a, 0, instructions, 0);
		}
		new_node = ft_lstnew(line);
		if (!new_node)
		{
			free(line);
			exit_checker(*stack_a, 0, instructions, 0);
		}
		ft_lstadd_back(instructions, new_node);
	}
	free(line);
}

/*
** it will iterate the list 'instructions' and call the
** implement_instruction() function to implement the called instruction.
*/

void	call_instruction(t_stack **stack_a, t_stack **stack_b,
			t_list *instructions)
{
	while (instructions)
	{
		implement_instruction(stack_a, stack_b,
			(char *)instructions->content);
		instructions = instructions->next;
	}
}

/*
** implements the given 'instruction' by sending stack_a and
** stack_b to the corresponding instruction in instructions.c.
*/

void	implement_instruction(t_stack **stack_a, t_stack **stack_b,
			char *instruction)
{
	if (!ft_strcmp("sa", instruction))
		sa(*stack_a, 0);
	if (!ft_strcmp("sb", instruction))
		sb(*stack_b, 0);
	if (!ft_strcmp("ss", instruction))
		ss(*stack_a, *stack_b, 0);
	if (!ft_strcmp("pa", instruction))
		pa(stack_a, stack_b, 0);
	if (!ft_strcmp("pb", instruction))
		pb(stack_a, stack_b, 0);
	if (!ft_strcmp("ra", instruction))
		ra(stack_a, 0);
	if (!ft_strcmp("rb", instruction))
		rb(stack_b, 0);
	if (!ft_strcmp("rr", instruction))
		rr(stack_a, stack_b, 0);
	if (!ft_strcmp("rra", instruction))
		rra(stack_a, 0);
	if (!ft_strcmp("rrb", instruction))
		rrb(stack_b, 0);
	if (!ft_strcmp("rrr", instruction))
		rrr(stack_a, stack_b, 0);
}

/*
** ends the program either if successful or if Error.
** 						0 - In case the program ended with Errors.
** 						1 - In case the prgram ended with stack_a not being
** 							sorted.
** 						2 - In case the program ended with stack_a being sorted.
*/

void	exit_checker(t_stack *stack_a, t_stack *stack_b, t_list **instructions,
			int status)
{
	if (stack_a)
		ft_dlst_clear(&stack_a);
	if (stack_b)
		ft_dlst_clear(&stack_b);
	if (*instructions)
	{
		while (*instructions)
		{
			free((*instructions)->content);
			ft_lstremove(instructions);
		}
	}
	if (!status)
		ft_putstr_fd("Error\n", 2);
	else if (status == 1)
		ft_putstr_fd("KO\n", 2);
	else if (status == 2)
	{
		ft_putstr_fd("OK\n", 1);
		exit(EXIT_SUCCESS);
	}
	exit(EXIT_FAILURE);
}
