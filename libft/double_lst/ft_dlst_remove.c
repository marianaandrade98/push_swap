#include "double_lst.h"

/*
** frees the memory of the element's content, making its previous
** element point to its next and its next point to its previous
** it also frees the element
*/

void	ft_dlst_remove(t_stack **stack)
{
	t_stack	*temp;

	if (!*stack)
		return ;
	temp = *stack;
	if (temp->next)
		temp->next->prev = temp->prev;
	if (temp->prev)
		temp->prev->next = temp->next;
	if (temp->prev)
		*stack = temp->prev;
	else
		*stack = temp->next;
	free(temp);
}
