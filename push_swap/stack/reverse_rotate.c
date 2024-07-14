#include "stack.h"

void rra(t_stacks *stacks)
{
	reverse_rotate(&stacks->stack_a);
}

void rrb(t_stacks *stacks)
{
	reverse_rotate(&stacks->stack_b);
}

void rrr(t_stacks *stacks)
{
	reverse_rotate(&stacks->stack_a);
	reverse_rotate(&stacks->stack_b);
}