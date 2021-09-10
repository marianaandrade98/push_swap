#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <stdio.h>

//void	sa(t_stack *stack_a, int p);
void	ft_swap_sa(t_stack *stack_a);
//void	sb(t_stack *stack_b, int p);
void	ft_swap_sb(t_stack *stack_b);
//void	ss(t_stack *stack_a, t_stack *stack_b, int p);
void	ft_swap_ss(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b, int p);
void	pb(t_stack **stack_a, t_stack **stack_b, int p);
//void	ra(t_stack **stack_a, int p);
void	ft_rotate_ra(t_stack **stack_a);
//void	rb(t_stack **stack_b, int p);
void	ft_rotate_rb(t_stack **stack_b);
//void	rr(t_stack **stack_a, t_stack **stack_b, int p);
void	ft_rotate_rr(t_stack **stack_a, t_stack **stack_b);
//void	rra(t_stack **stack_a, int p);
void	ft_rrotate_rra(t_stack **stack);
// void	rrb(t_stack **stack_b, int p);
void	ft_rrotate_rrb(t_stack **stack);
// void	rrr(t_stack **stack_a, t_stack **stack_b, int p);
void	ft_rrotate_rrr(t_stack **stack_a, t_stack **stack_b);

void	validations(int argc, char **argv, int i);
void	build_stack(int input, t_stack **stack);
void	sorting(t_stack **stack_a, t_stack **stack_b);
void	algo_small(t_stack **stack);
void	sort_3(t_stack **stack_a);
int	    middle_numb(t_stack **stack_a);
void	stackA_to_stackB(t_stack **stack_a, t_stack **stack_b);
int	    verify_to_send(t_stack **stack_a);
void	verify_pos(t_stack **stack_a, t_stack **stack_b);

# endif