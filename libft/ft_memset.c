#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned int i;
	char	*arr = (char *)s;
	i = 0;
	while (i < n)
		arr[i++] = c;
	return (s);
}