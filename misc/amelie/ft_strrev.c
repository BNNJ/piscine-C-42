#include <stdio.h>

char *ft_strrev(char *str)
{
	int count = 0, moitie;
	char temp;

	while (str[count])
		count++;
	if (count % 2 == 1)	
		moitie = (count - 1) / 2;
	else
		moitie = count / 2;
	for (int i = 0; i < moitie; i++)
	{
		temp = str[i];
		str[i] = str[count - i - 1];
		str[count - i - 1] = temp;
	}
	return str;
}

int	main()
{
	char str[] = "Hello Darkness";

	printf("%s\n", ft_strrev(str));
	return 0;
}