#include "ft_printf.h"

int	rec_puthex(unsigned long long num, char *hex)
{
	int	i;

	if (num <= 0)
		return (0);
	i = rec_puthex(num / 16, hex);
	ft_putchar(hex[num % 16]);
	return (i + 1);
}

int	ft_putlhex(unsigned int num)
{
	int	i;

	i = 0;
	if (num == 0)
		i += ft_putchar('0');
	else
		i += rec_puthex(num, "0123456789abcdef");
	return (i);
}

int	ft_putuhex(unsigned int num)
{
	int	i;

	i = 0;
	if (num == 0)
		i += ft_putchar('0');
	else
		i += rec_puthex(num, "0123456789ABCDEF");
	return (i);
}

int	ft_putptr(void *ptr)
{
	int	i;
	
	if (ptr == NULL)
		return (ft_putstr("(nil)"));
	i = ft_putstr("0x");
	if (ptr == 0)
		i += ft_putchar(0);
	else
		i += rec_puthex((unsigned long long) ptr, "0123456789abcdef");
	return (i);
}