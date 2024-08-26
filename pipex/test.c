#include <unistd.h>

int main()
{
	write(2, "err", 3);
	write(1, "out", 3);
}