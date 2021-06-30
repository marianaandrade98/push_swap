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

void	sa(t_list *list_a, t_list *list_b, int p);
void	sb(t_list *list_a, t_list *list_b, int p);
void	ss(t_list *list_a, t_list *list_b, int p);
void	pa(t_list **list_a, t_list **list_b, int p);
void	pb(t_list **list_a, t_list **list_b, int p);

# endif