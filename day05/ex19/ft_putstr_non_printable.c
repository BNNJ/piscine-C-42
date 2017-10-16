#include <unistd.h>

void	ft_puthex(const unsigned char c)
{
	char base[16] = "0123456789abcdef";

	write(1, base + c / 16, 1);
	write(1, base + c % 16, 1);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str)
	{
		if (*str >= 32 && *str <= 126) 
			write(1, str, 1);
		else
		{
			write(1, "\\", 1); 
			ft_puthex(*str);
		}
		++str;
	}
}

int		main(int argc, char **argv)
{
	char *str = (argc == 2) ? argv[1] : "Hello\nDarkness\tMy\rOld\fFriend";

	ft_putstr_non_printable(str);
	return 0;
}