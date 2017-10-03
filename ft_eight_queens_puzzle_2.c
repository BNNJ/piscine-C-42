#include <unistd.h>
#define N 8

void	ft_print_board(int *board)
{
	int i;

	i = 0;
	while (i <= N - 1)
	{
		board[i] += '0';
		write(1, &board[i], 1);
		board[i] -= '0';
		i++;
	}
	write(1, "\n", 1);
}

int		is_valid(int *board, int col, int row)
{
	int i = 1;

	while (i <= col)
	{
		if (board[col - i] == row - i || board[col - i] == row 
				|| board[col - i]  == row + i)
			return 0;
		i++;
	}
	return 1;
}

// Function to find only one solution to the N queens problem
/*
int		ft_place_queens(int *board, int col)
{
	int row = 1;

	if (col == N)
	{
		ft_print_board(board);
		return 1;
	}
	while (row <= N)
	{
		if (is_valid(board, col, row))
		{
			board[col] = row;
			if (ft_place_queens(board, col + 1))
				return 1;
		}
		row++;
	}
	return 0;
}
*/

// Function to find all solutions to the N queens problem
void	ft_place_queens(int *board, int col)
{
	int row = 1;

	if (col == N)
		ft_print_board(board);
	while (row <= N)
	{
		if (is_valid(board, col, row))
		{
			board[col] = row;
			ft_place_queens(board, col + 1);
		}
		row++;
	}
}


void	ft_eight_queens_puzzle_2()
{
	int board[N];

	ft_place_queens(board, 0);
}

int		main()
{
	ft_eight_queens_puzzle_2();
	return 0;
}