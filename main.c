#include "push_swap.h"


int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*head;
	int		i;
	int		p;

	if (argc < 2)
		return (0);
	i = 1;
	stack_a = NULL;
	stack_b = NULL;

	while (argv[i])
	{
		p = ft_atoi(argv[i]);
		ft_lstadd_back(&stack_a, ft_lstnew((void *)(size_t)p));
		i++;
	}
	sort_3(&stack_a);

	
	
	
	printf("stack A\n");
	while (stack_a)
	{
		printf("%d, \n", (int)stack_a->content);	
		stack_a = stack_a->next;
	}
	printf("stack B\n");
	while (stack_b)
	{
		printf("%d, \n", (int)stack_b->content);
		stack_b = stack_b->next;
	}
}
