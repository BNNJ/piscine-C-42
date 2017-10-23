#include "sudoku.h"

int		sudoku(char **grid, int row, int col);

void	print_grid(char **grid)
{
	int i;

	i = 0;
	while (i < 9)
	{
		while (*grid[i])
		{
			write(1, grid[i]++, 1);
			write(1, " ", 1);
		}
		write(1, "\n", 1);
		++i;
	}
}

char	**set_grid(char **argv)
{
	int col;
	int row;
	char **grid;

	row = 0;
	if (!(grid = malloc(sizeof(char*) * 9)))
	{
		write(1, "Error : invalid malloc", 22);
		return 0;
	}
	while (row < 9)
	{
		col = 0;
		grid[row] = malloc(10);
		while (col < 9)
		{
			grid[row][col] = argv[row + 1][col];
			++col;
		}
		grid[row][col] = '\0';
		++row;
	}
	return grid;
}

int		main(int argc, char **argv)
{
	char **grid;

	if (argc != 10)
		write(1, "Error : invalid grid\n", 21);
 	else
 	{
		grid = set_grid(argv);
		if (sudoku(grid, 0, 0))
			print_grid(grid);
		else 
			write(1, "Error : invalid grid\n", 21);
	}
	return 0;
}
