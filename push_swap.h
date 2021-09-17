#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <stdio.h>

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

void		validations(int argc, char **argv, int i);
void		build_stack(int input, t_stack **stack);
void		sorting(t_stack **stack_a, t_stack **stack_b);
void		algo_3(t_stack **stack);
void		algo_5(t_stack **stack_a, t_stack **stack_b);
int			is_down_middle(t_stack *stack, int min);

#endif