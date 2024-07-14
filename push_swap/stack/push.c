#include "stack.h"

void pa(t_stacks *stacks)
{
	push(&stacks->stack_a, pop(&stacks->stack_b));
}

void pb(t_stacks *stacks)
{
	push(&stacks->stack_b, pop(&stacks->stack_a));
}
