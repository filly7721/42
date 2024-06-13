#include "libft.h"

void	*ft_calloc(size_t nelem, size_t elsize)
{
	unsigned int	size;
	void			*arr;

	size = nelem * elsize;
	if (elsize != 0 && size / elsize != nelem)
		return (NULL);
	arr = malloc(nelem * elsize);
	if (!arr)
		return (NULL);
	ft_memset(arr, 0, nelem * elsize);
	return (arr);
}
