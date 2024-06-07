#include "libft.h"

int	ft_isprint(int c)
{
	if ((c >= 32 && c < 127) || c == ' ')
			return (1);
	return (0);
}