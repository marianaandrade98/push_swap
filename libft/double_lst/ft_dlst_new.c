#include "double_lst.h"

/*
**  create new node
*/

t_stack	*ft_dlst_new(int content)
{
	t_stack	*temp;

	temp = (t_stack *)malloc(sizeof(t_stack));
	if (temp == NULL)
		return (0);
	temp->data = content;
	temp->next = NULL;
	temp->prev = NULL;
	return (temp);
}
