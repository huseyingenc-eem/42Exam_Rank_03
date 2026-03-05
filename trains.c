#include <stdio.h>
#include <stdlib.h>


int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int is_safe(int*board, int col, int row)
{
  int prev=0;

  while(prev< col)
  {
    if (board[prev]== row)
      return 0;
    if (ft_abs(board[prev]- row)== col-prev)
      return 0;
    prev++;
  }
  return 1;
}
void	print_solution(int *board, int queens)
{
	int index = 0;

	while (index < queens)
	{
		fprintf(stdout, "%d", board[index]);
		if (index < queens - 1)
			fprintf(stdout, " ");
		index++;
	}
	fprintf(stdout, "\n");
}
void	solve(int *board, int col, int queens)
{
	int row = 0;

	if (col == queens)
	{
		print_solution(board, queens);
		return ;
	}
	while (row < queens)
	{
		if (is_safe(board, col, row))
		{
			board[col] = row;
			solve(board, col + 1, queens);
		}
		row++;
	}
}
int	main(int argc, char *argv[])
{
	int queens = 0;
	int *board;

	if (argc != 2)
		return (1);

	queens = atoi(argv[1]);
	if (queens <= 0)
		return (1);
	board = malloc(sizeof(int) * queens);
	if (!board)
		return (1);
	solve(board, 0, queens);

	return (0);
}
