#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_print_stuff(char i, char j, char k)
{
	ft_putchar(i);
	ft_putchar(j);
	ft_putchar(k);
	if (i != '7')
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void ft_print_comb(void)
{
    char i = '0';
    char j = '1';
    char k = '2';
    
    while (i < j)
    {
        j = i + 1;
    	while (j < k)
    	{
            k = j + 1;
    		while (k <= '9')
    		{
    			ft_print_stuff(i, j, k);
    			++k;
    		}
    		++j;
    	}
    	++i;
    }
}

/*
void ft_print_comb(void)
{
    char i = '0';
    char j = '1';
    char k = '2';

    while (i < '8')
    {
        ft_print_stuff(i, j, k);
        ++k;
        if (k > '9')
        {
            ++j;
            k = j + 1;
        }
        if (j > '8')
        {
            ++i;
            j = i + 1;
            k = j + 1;
        }
    }
}
*/

int main()
{
    ft_print_comb();
    return 0;
}