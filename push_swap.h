/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandrade <mandrade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:35:13 by mandrade          #+#    #+#             */
/*   Updated: 2021/10/13 17:20:22 by mandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <stdio.h>

# ifndef MAX_SIZE
# define MAX_SIZE 20
# endif

/*
** push swap actions in swap.c, push.c, reverse.c and rotate.c
*/
void		sa(t_stack *stack_a, int p);
void		sb(t_stack *stack_b, int p);
void		ss(t_stack *stack_a, t_stack *stack_b, int p);
void		pa(t_stack **stack_a, t_stack **stack_b, int p);
void		pb(t_stack **stack_a, t_stack **stack_b, int p);
void		ra(t_stack **stack_a, int p);
void		rb(t_stack **stack_b, int p);
void		rr(t_stack **stack_a, t_stack **stack_b, int p);
void		rra(t_stack **stack_a, int p);
void		rrb(t_stack **stack_b, int p);
void		rrr(t_stack **stack_a, t_stack **stack_b, int p);

/*
** main functions
*/
void		sorting(t_stack **stack_a, t_stack **stack_b);
void		sort_3(t_stack **stack_a);
void		sort_5(t_stack **stack_a, t_stack **stack_b);

/*
** utils.c
*/
void		build_stack(char **argv, t_stack **stack_a);
void		exit_program(t_stack *stack_a, t_stack *stack_b, int status);

/*
** main_utils.c
*/
void		push_min_to_b(t_stack **stack_a, t_stack **stack_b);

/*
** main_utils.c
*/
int			count_in_between(t_stack *stack_a, t_stack *limits);

#endif