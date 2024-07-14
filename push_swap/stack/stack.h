#ifndef STACK_H
# define STACK_H

# include <stdlib.h>

typedef struct s_node
{
	int				data;
	struct s_node	*next;
}	t_node;

void	swap( t_node** stack);
void	push(t_node** stack, t_node* node);
t_node	*pop(t_node** stack);
void	rotate(t_node** stack);
void	reverse_rotate(t_node** stack);

int		stack_length(t_node	*stack);

typedef struct s_stacks
{
	t_node	*stack_a;
	t_node	*stack_b;
}	t_stacks;

void sa(t_stacks *stacks);
void sb(t_stacks *stacks);
void ss(t_stacks *stacks);

void pa(t_stacks *stacks);
void pb(t_stacks *stacks);

void ra(t_stacks *stacks);
void rb(t_stacks *stacks);
void rr(t_stacks *stacks);

void rra(t_stacks *stacks);
void rrb(t_stacks *stacks);
void rrr(t_stacks *stacks);

#endif