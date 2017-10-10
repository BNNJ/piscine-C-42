#include <unistd.h>

/* lol
void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_print_alphabet(void)
{
    int i = 'a';
    
    while(i <= 'z')
    {
        ft_putchar(i);
        ++i;
    }
}
*/

void ft_print_alphabet(void)
{
	write(1, "abcdefghijklmnopqrstuvwxyz", 26);
}


int main()
{
    ft_print_alphabet();
    return 0;
}