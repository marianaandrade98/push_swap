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
void		algo_500(t_stack **stack_a, t_stack **stack_b);
int			part_1(t_stack **stack_a, t_stack **stack_b);
int			ft_dlst_median(t_stack *stack);
t_stack		*builder(t_stack *stack);
int			aux_median_check(t_stack *stack_a, int median);
int			median_pos(t_stack *temp, int median);
void		part_1_cont(t_stack **stack_a, t_stack **stack_b, int aux_median,
			int median);
int			pos_check(t_stack *stack_a, int value);
void		presort_b_500(t_stack **stack_b, t_stack **stack_a, int median);
void		sort_b_500(t_stack **stack_b, t_stack **stack_a, int min);
void		sort_b_start(t_stack **stack_a, int min);
int			rotate_choice(t_stack *stack, int median);
int			rotate_choice_limits(t_stack *stack, int size, int limit);
int			part_2(t_stack **stack_a, t_stack **stack_b, int min);
int			rotate_choice_2(t_stack *stack, int median, int limit);
int			part_3(t_stack **stack_a, t_stack **stack_b, int min);
void		part_4(t_stack **stack_a, t_stack **stack_b, int min);
int			rotate_choice_3(t_stack *stack, int median);
int			aux_median_min(t_stack *stack_a, int median);

#endif