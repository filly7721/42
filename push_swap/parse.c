/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalaab <ashalaab@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:03:14 by ashalaab          #+#    #+#             */
/*   Updated: 2024/07/16 17:03:15 by ashalaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	clear_ints(t_list	*head)
{
	ft_lstclear(&head, &free);
	return (0);
}

int	add_int(t_list **head, int n)
{
	int		*num;
	t_list	*node;

	num = malloc(sizeof(int));
	if (!num)
		return (0);
	*num = n;
	node = ft_lstnew(num);
	if (!node)
	{
		free(num);
		return (0);
	}
	ft_lstadd_front(head, node);
	return (1);
}

int	skip_whitespace(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	return (i);
}

int	parse_ints(char *str, t_list **head)
{
	int		i;
	int		sign;
	long	res;

	i = skip_whitespace(str);
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		res = 0;
		sign = 1;
		if (str[i] == '-' || str[i] == '+')
			if (str[i++] == '-')
				sign = -1;
		if (!ft_isdigit(str[i]))
			return (0);
		while (ft_isdigit(str[i]) && res <= ((long)2147483647 + (sign == -1)))
			res = res * 10 + str[i++] - '0';
		if (res > ((long)2147483647 + (sign == -1)) || !ft_strchr(" ", str[i]))
			return (0);
		i += skip_whitespace(str + i);
		if (!add_int(head, sign * res))
			return (0);
	}
	return (1);
}

int	parse_input(int count, char **strs, t_stacks *stacks)
{
	int		i;
	t_list	*head;
	t_list	*curr;

	i = 0;
	head = NULL;
	while (i < count)
		if (!parse_ints(strs[i++], &head))
			return (clear_ints(head));
	if (!create_arrays(stacks, ft_lstsize(head)))
		return (clear_ints(head));
	curr = head;
	while (curr)
	{
		push(stacks->stack_a, *(int *)curr->content);
		curr = curr->next;
	}
	clear_ints(head);
	return (1);
}
