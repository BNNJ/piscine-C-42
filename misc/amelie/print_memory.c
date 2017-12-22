#include <stdio.h>
#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void print_hexa(long nb)
{
	char base[] = "0123456789abcedf";

	if (nb / 16 > 0)
		print_hexa(nb / 16);
	write(1, base + nb % 16, 1);
}

void *ft_print_memory(void *addr, unsigned int size)
{
	unsigned int i = 0, temp = 0;
	char *c = (char*)addr;

	while (temp <= size)
	{
		print_hexa((long)addr + temp);
		ft_putchar(':');
		while (i < 16 && temp + i < size)
		{
			if (c[temp + i] < 16)
				ft_putchar('0');
			print_hexa(c[temp + i]);
			i++;
			if (i % 2 == 0 || temp + i == size)
				ft_putchar(' ');
		}
		i = 0;
		while (i < 16 && temp + i < size)
		{
			if ((c[temp + i] >= 0 && c[temp + i] <= 31) || c[temp + i] == 127)
				ft_putchar('.');
			else
				write (1, addr + temp + i, 1);
			i++;
			if (i % 16 == 0 || temp + i == size)
				ft_putchar('\n');
		}
		temp += 16;
		i = 0;
	}
	return addr;
}

/* -------------------------------------------------------------------------- */

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

void	*ft_print_memory2(void *addr, unsigned int size)
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
	unsigned int size = 70;
	char bla[] = "Holy shit \t i have \f no idea what i'm doing and what is this ?";
	void *ptr;

	ptr = bla;
	ft_print_memory(ptr, size);
	write(1, "\n------------------------------\n", 32);
	ft_print_memory2(ptr, size);
	return 0;
}