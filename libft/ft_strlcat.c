#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;

	j = ft_strlen(dst);
	if (size <= j)
		return (ft_strlen(src) + size);
	i = 0;
	while (src[i] != '\0' && i < size - j - 1)
	{
		dst[j + i] = src[i];
		i++;
	}
	dst[j + i] = '\0';
	return (ft_strlen(src) + j);
}
