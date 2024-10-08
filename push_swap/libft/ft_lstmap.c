/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalaab <ashalaab@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:43:38 by ashalaab          #+#    #+#             */
/*   Updated: 2024/06/14 12:43:38 by ashalaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*map;
	t_list	*curr;

	if (!lst)
		return (NULL);
	map = ft_lstnew(f(lst->content));
	curr = map;
	lst = lst->next;
	while (lst && curr)
	{
		curr->next = ft_lstnew(f(lst->content));
		curr = curr->next;
		lst = lst->next;
	}
	if (curr == NULL)
	{
		ft_lstclear(&map, del);
		return (NULL);
	}
	return (map);
}
