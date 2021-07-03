#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}					t_list;

void	sa(t_list *stack_a, int p);
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

# endif