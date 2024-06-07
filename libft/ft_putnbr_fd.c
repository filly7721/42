#include "libft.h"

static void	rec_putnbr_fd(unsigned int n, int fd)
{
	char	c;

	if (n == 0)
		return;
	c = n % 10 + '0';
	rec_putnbr_fd(n / 10, fd);
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
		write(fd, "0", 1);
	else if (n > 0)
		rec_putnbr_fd(n, fd);
	else
	{
		write(fd, "-", 1);
		rec_putnbr_fd(-n, fd);
	}
}