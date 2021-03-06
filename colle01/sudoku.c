int	is_valid(const char c, char **grid, const int y, const int x)
{
	int i;

	i = 0;
	while (i < 9)
	{
		if (grid[y][i] == c || grid[i][x] == c)
			return 0;
		++i;
	}
	return ((c == grid[(y / 3) * 3 + (y + 1) % 3][(x / 3) * 3 + (x + 1) % 3])
		|| (c == grid[(y / 3) * 3 + (y + 2) % 3][(x / 3) * 3 + (x + 1) % 3])
		|| (c == grid[(y / 3) * 3 + (y + 1) % 3][(x / 3) * 3 + (x + 2) % 3])
		|| (c == grid[(y / 3) * 3 + (y + 2) % 3][(x / 3) * 3 + (x + 2) % 3]));
}

int	sudoku(char **grid, int row, int col) 
{
	char c;

	c = '0';
	if (row == 9)
		return 1;
	if (grid[row][col] != '.')
		return (col < 8) ? sudoku(grid, row, col + 1)
				 : sudoku(grid, row + 1, 0);
	while (++c <= '9')
	{
		if (is_valid(c, grid, row, col))
		{
			grid[row][col] = c;
			if (col < 8)
			{
				if (sudoku(grid, row, col + 1))
					return 1;
			}
			else
				if (sudoku(grid, row + 1, 0))
					return 1;
			grid[row][col] = '.';
		}
	}
	return 0;
}
