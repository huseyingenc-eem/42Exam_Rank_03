#include <stdio.h>
#include <stdlib.h>

#define ABS(x) ((x) < 0 ? -(x) : (x))

int same_row(int *queens, int col, int row) {
  int i;

  i = 0;
  while (i < col) {
    if (queens[i] == row)
      return (1);
    i++;
  }
  return (0);
}

int same_diagonal(int *queens, int col, int row) {
  int i;

  i = 0;
  while (i < col) {
    if (ABS(queens[i] - row) == col - i)
      return (1);
    i++;
  }
  return (0);
}

int is_safe(int *queens, int col, int row) {
  return (!same_row(queens, col, row) && !same_diagonal(queens, col, row));
}

void print_solution(int *queens, int size) {
  int i;

  i = 0;
  while (i < size) {
    printf("%d", queens[i]);
    if (i < size - 1)
      printf(" ");
    i++;
  }
  printf("\n");
}

void solve(int *queens, int col, int size) {
  int row;

  if (col == size) {
    print_solution(queens, size);
    return;
  }
  row = 0;
  while (row < size) {
    if (is_safe(queens, col, row)) {
      queens[col] = row;
      solve(queens, col + 1, size);
    }
    row++;
  }
}

int main(int ac, char **av) {
  int size;
  int *queens;

  if (ac != 2)
    return (1);
  size = atoi(av[1]);
  if (size <= 0)
    return (1);
  queens = malloc(sizeof(int) * size);
  if (!queens)
    return (1);
  solve(queens, 0, size);
  free(queens);
  return (0);
}
