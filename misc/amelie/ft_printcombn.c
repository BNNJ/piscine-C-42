#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void ft_putchar (char c)
{
	write (1, &c, 1);
}

int puissance1(int n)
{
	int puissance = 1, i = n;
	while (i > 0)
	{
		puissance *= 10;
		i--;
	}
	puissance /= 10;
	return puissance;
}

int test_nombre(int i, int puissance)
{
	int r = i;
	if (puissance >= 10)
	{
		int k = i / puissance;
		int j = (i % puissance) / (puissance / 10);
		if (k >= j)
			return 0;
		else 
		{
			puissance /= 10;
			test_nombre(i % (puissance * 10), puissance);
		}
	}
	else
		return r;
}

void ft_print_combn(int n)
{
	int i, j;
	int puissance = puissance1(n); 
	int k;
	int decompte; 

	for(j = 1; j < puissance * 10; j++)
	{
		if (test_nombre(j, puissance) != 0)
		{
			k = j;
			decompte = puissance;
			while (decompte > 0)
			{
				i = k / decompte;
				ft_putchar(i + 48);
				k %= decompte;
				decompte /= 10;
			}
			if (j / puissance != 10 - n)
				write(1, ", ", 2);
		}
	}
}

int main(int argc, char **argv)
{
	int n; 
	
	if (argc == 2)
	{
		n = atoi(argv[1]);
		if (n > 0 && n < 11)
		{
			ft_print_combn(n);
			write (1, "\n", 1);
		}
		else
			write(1, "Please enter a number between 1 and 10\n", 39);
	}
	return 0;
}