#include "test.h"

t_node	*create_node(int i)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	node->data = i;
	node->next = NULL;
	return (node);
}

void	print_stacks(t_stacks stacks)
{
	t_node	*node;
	
	node = stacks.stack_a;
	printf("a: ");
	while (node)
	{
		printf("%i ", node->data);
		node = node->next;
	}
	printf("\n");
	node = stacks.stack_b;
	printf("b: ");
	while (node)
	{
		printf("%i ", node->data);
		node = node->next;
	}
	printf("\n");
}

void	sort_2(t_stacks *stacks)
{
	if (stacks->stack_a->data > stacks->stack_a->next->data)
		sa(stacks);
}

void	sort_3(t_stacks *stacks)
{
	//TODO
	return ;
}

void	radix_sort(t_stacks	*stacks)
{
	int	i;
	int	count;

	i = 0;
	while (i < 10)
	{
		count = stack_length(stacks->stack_a);
		while (count--)
		{
			if ((stacks->stack_a->data >> i & 1) == 0)
				pb(stacks);
			else
				rra(stacks);
		}
		count = stack_length(stacks->stack_b);
		while (count--)
			pa(stacks);
		i++;
	}
}

void	sort(t_stacks *stacks)
{
	int	length;

	length = stack_length(stacks->stack_a);

	if (length < 2)
		return ;
	if (length == 2)
		sort_2(stacks);
	else if (length == 3)
		sort_3(stacks);
	else
		radix_sort(stacks);
}

int main()
{
	t_stacks stacks;

	push(&stacks.stack_a, create_node(2));
	push(&stacks.stack_a, create_node(7));
	push(&stacks.stack_a, create_node(4));
	push(&stacks.stack_a, create_node(18));
	push(&stacks.stack_a, create_node(0));
	push(&stacks.stack_a, create_node(16));
	push(&stacks.stack_a, create_node(90));
	push(&stacks.stack_a, create_node(52));
	push(&stacks.stack_a, create_node(81));
	push(&stacks.stack_a, create_node(55));

	print_stacks(stacks);

	sort(&stacks);

	print_stacks(stacks);
}