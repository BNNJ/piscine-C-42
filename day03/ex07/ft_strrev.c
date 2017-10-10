#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

char *ft_strrev(char *str)
{
	char a;
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
		str[i++];
	while (i-- > j)
	{
		a = str[i];
		str[i] = str[j];
		str[j++] = a;
	}
	return str;
}

int main()
{
	char str[] = "Hello Darkness";
	int i = 0;

	while (str[i])
		ft_putchar(str[i++]);
	ft_putchar('\n');
	ft_strrev(str);
	i = 0;
	while (str[i])
		ft_putchar(str[i++]);
	return 0;
}