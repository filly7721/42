#include "stack.h"

void ra(t_stacks *stacks)
{
	rotate(&stacks->stack_a);
}

void rb(t_stacks *stacks)
{
	rotate(&stacks->stack_b);
}

void rr(t_stacks *stacks)
{
	rotate(&stacks->stack_a);
	rotate(&stacks->stack_b);
}