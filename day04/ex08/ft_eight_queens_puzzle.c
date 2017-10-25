#include <unistd.h>
#define N 8

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putnbr(int nb)
{
	unsigned int nbr = nb;

	if (nb < 0)
	{
		ft_putchar('-');
		nbr *= -1;
	}
	if (nbr / 10 > 0)
		ft_putnbr(nbr / 10);
	ft_putchar(nbr % 10 + '0');
}

int		is_valid(int *board, int col, int row)
{
	int i = 1;

	while (i <= col)
	{
		if (board[col - i] == row - i || board[col - i] == row 
				|| board[col - i]  == row + i)
			return 0;
		++i;
	}
	return 1;
}

int		ft_count_solutions(int *board, int col, int count)
{
	int row = 1;

	if (col == N)
		++count;
	while (row <= N)
	{
		if (is_valid(board, col, row))
		{
			board[col] = row;
			count = ft_count_solutions(board, col + 1, count);
		}
		++row;
	}
	return count;
}

void	ft_eight_queens_puzzle()
{
	int board[N];
	int count = 0;

	ft_putnbr(ft_count_solutions(board, 0, count));
}

int		main()
{
	ft_eight_queens_puzzle();
	return 0;
}
