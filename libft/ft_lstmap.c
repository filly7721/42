#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*map;
	t_list	*curr;

	map = ft_lstnew(f(lst->content));
	curr = map;
	lst = lst->next;
	while(lst && curr)
	{
		curr->next = ft_lstnew(f(lst->content));
		curr = curr->next;
		lst = lst->next;
	}
	if(curr == NULL)
	{
		ft_lstclear(&map, del);
		return (NULL);
	}
	return (map);
}