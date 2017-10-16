#include <unistd.h>
#include <stdlib.h>

void	ft_print_address(const  unsigned long long int n, int i)
{
	const char *base;

	base = "0123456789abcdef";
	if (n / 16 > 0)
		ft_print_address(n / 16, i + 1);
	else if (i < 8)
		while (++i <= 8)
			write(1, "0", 1);
	write(1, base + n % 16, 1);
}

void	ft_print_hex(const unsigned char c, const int j, const int size)
{
	const char base[16] = "0123456789abcdef";

	if (j <= size)
	{
		write(1, base + c / 16, 1);
		write(1, base + c % 16, 1);
	}
	else 
		write(1, "  ", 2);
	if (j % 2 == 0)
		write(1, " ", 1);
}

void	ft_print_char(const char c, const int j, const int size)
{
	if (j > size)
		write(1, " ", 1);
	else if (c >= 32 && c <= 126) 
		write(1, &c, 1);
	else 
		write(1, ".", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	while (i < size)
	{
		ft_print_address((unsigned long long int)(addr + i), 1);
		write(1, ": ", 2);
		j = i;
		while (++j <= 16 + i)
			ft_print_hex(*(unsigned char*)(addr + j - 1), j, size);
		write(1, " ", 1);
		j = i;
		while (++j <= 16 + i)
			ft_print_char(*(unsigned char*)(addr + j - 1), j, size);
		write(1, "\n", 1);
		i += 16;
	}
	return addr;
}

int		main()
{
	unsigned int size = 64;
	char bla[] = "Holy shit i have no idea what i'm doing and what is this ?";
	void *ptr;

	ptr = bla;
	ft_print_memory(ptr, size);
	return 0;
}