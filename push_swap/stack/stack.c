#include "stack.h"

void swap(t_node** stack)
{
	t_node*	temp;

	if (!*stack || !(*stack)->next)
		return ;
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	temp->next = *stack;
	*stack = temp;
}

void	push(t_node** stack, t_node* node)
{
	if (!*stack)
	{
		*stack = node;
		node->next = NULL;
	}
	else
	{
		node->next = *stack;
		*stack = node;
	}
}

t_node	*pop(t_node** stack)
{
	t_node	*temp;
	
	temp = *stack;
	if (!temp)
		return (NULL);
	*stack = temp->next;
	temp->next = NULL;
	return (temp);
}

void	rotate(t_node** stack)
{
	t_node	*prev;
	t_node	*curr;

	if (!*stack || !(*stack)->next)
		return ;
	curr = *stack;
	while (curr->next)
	{
		prev = curr;
		curr = curr->next;
	}
	prev->next = NULL;
	curr->next = *stack;
	*stack = curr;
}

void	reverse_rotate(t_node** stack)
{
	t_node	*temp;

	if (!*stack || !(*stack)->next)
		return ;
	temp = *stack;
	while (temp->next)
		temp = temp->next;

	temp->next = *stack;
	temp = *stack;
	*stack = temp->next;
	temp->next = NULL;
}