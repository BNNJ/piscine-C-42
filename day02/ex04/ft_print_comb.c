#include <unistd.h>

void ft_print_comb(void)
{
    char i;
    char j;
    char k;
    
    i = '0';
    while (i <= '7')
    {
        j = i + 1;
    	while (j <= '8')
    	{
            k = j + 1;
    		while (k <= '9')
    		{
                write(1, &i, 1);
                write(1, &j, 1);
                write(1, &k, 1);
                if (i != '7')
                    write(1, ", ", 2);
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
	write(1, &i, 1);
	write(1, &j, 1);
	write(1, &k, 1);
	if (i != '7')
		write(1, ", ", 2);
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
