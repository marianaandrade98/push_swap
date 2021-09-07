#include "push_swap.h"


int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;
	int		p;

	i = 1;
	stack_a = NULL;
	stack_b = NULL;
	while (argv[i])
	{
		p = ft_atoi(argv[i]);
		ft_lstadd_back(&stack_a, ft_lstnew((void *)(size_t)p));
		i++;
	}
	
	
	printf("stack A\n");
	while (stack_a)
	{
		printf("%d, \n", stack_a->data);	
		stack_a = stack_a->next;
	}
	printf("stack B\n");
	while (stack_b)
	{
		printf("%d, \n", stack_b->data);
		stack_b = stack_b->next;
	}
	
	ft_dlst_clear(&stack_a);
	ft_dlst_clear(&stack_b);
	return (0);
}
