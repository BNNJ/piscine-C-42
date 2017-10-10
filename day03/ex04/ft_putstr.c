#include <unistd.h>

void ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int main(int argc, char **argv)
{
	ft_putstr(argv[1]);
	return 0;
}