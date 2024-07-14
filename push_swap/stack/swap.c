#include "stack.h"

void	sa(t_stacks *stacks)
{
	swap(&stacks->stack_a);
}

void sb(t_stacks *stacks)
{
	swap(&stacks->stack_b);
}

void ss(t_stacks *stacks)
{
	swap(&stacks->stack_b);
	swap(&stacks->stack_a);
}