#include "libft.h"

static int	digit_count(int n)
{
	int	size;

	size = (n <= 0);
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	unsigned int	num;
	char			*res;
	int				size;

	num = n;
	if (n < 0)
		num = -n;
	size = digit_count(n);
	res = malloc(sizeof(char) * (size + 1));
	res[size] = '\0';
	while (--size >= (n < 0))
	{
		res[size] = num % 10 + '0';
		num /= 10;
	}
	if (size == 0)
		res[0] = '-';
	return (res);
}
