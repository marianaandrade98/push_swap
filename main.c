#include "push_swap.h"
#include <stdio.h>

int	main()
{
	t_list	*stack_a;
	t_list	*current;

	stack_a = NULL;

	int *p = malloc(sizeof(int));
	if (!p)
		return 0;
	*p = 2;
	ft_lstadd_back(&stack_a, ft_lstnew(p));
	current = stack_a;
	p = malloc(sizeof(int));
	*p = 1;
	ft_lstadd_back(&stack_a, ft_lstnew(p));
	p = malloc(sizeof(int));
	*p = 3;
	ft_lstadd_back(&stack_a, ft_lstnew(p));
	
	sort_3(stack_a);

	while (current)
	{
		printf("%d, ", current->content);
		current = current->next;
	}

}

/*
void print(Node *head) {
    Node *current_node = head;
   	while ( current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
*/
