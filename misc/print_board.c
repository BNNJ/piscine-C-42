void print_board(int board[4][4], int x, int y)
{
	int i;
	int j;

	i = 0;
	while (i <= 8)
	{
		j = -1;
		if (i % 2 == 0)
		{
			if (i == y * 2 || i == y * 2 + 2)
			{
				while (++j < x * 3)
					write(1, " ", 1);
				write(1, "+--+\n", 5);
			}
			else
				write(1, "\n", 1);
		}
		else
		{
			while (++j <= 12)
			{
				if ((j == x * 3 || j == x * 3 + 3) && i == y * 2 + 1)
					write(1, "|", 1);
				else if (j % 3 == 0)
					write(1, " ", 1);
				else
				{
					ft_putnbr(board[i/2][j/3]);
					++j;
				}
			}
			write(1, "\n", 1);
		}
		++i;
	}
}
