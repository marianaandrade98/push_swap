#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <stdio.h>

typedef struct
{
	int			*stack;

}					info;

void	sa(t_list **stack_a, int p);
void	sb(t_list *stack_b, int p);
void	ss(t_list *stack_a, t_list *stack_b, int p);
void	pa(t_list **stack_a, t_list **stack_b, int p);
void	pb(t_list **stack_a, t_list **stack_b, int p);
void	ra(t_list **stack_a, int p);
void	rb(t_list **stack_b, int p);
void	rr(t_list **stack_a, t_list **stack_b, int p);
void	rra(t_list **stack_a, int p);
void	rrb(t_list **stack_b, int p);
void	rrr(t_list **stack_a, t_list **stack_b, int p);

void	sort_3(t_list **stack_a);
int	    middle_numb(t_list **stack_a);
void	stackA_to_stackB(t_list **stack_a, t_list **stack_b);
int	    verify_to_send(t_list **stack_a);
void	verify_pos(t_list **stack_a, t_list **stack_b);

# endif