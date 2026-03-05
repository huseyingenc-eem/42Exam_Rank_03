#include <stdio.h>
#include <stdlib.h>


void	printSubset(int *arr, int *path, int len)
{
	int index = -1;
	int first = 1;

	while (++index < len)
	{
		if (path[index])
		{
			if (!first)
				printf(" ");
			printf("%d", arr[index]);
			first = 0;
		}
	}
	printf("\n");
}

void	backtrack(int *arr, int *path, int len, int idx, int sum, int target)
{
	if (idx == len)
	{
		if (sum == target)
		{
			printSubset(arr, path, len);
		}
		return;
	}
	path[idx] = 1;
	backtrack(arr, path, len, idx + 1, sum + arr[idx], target);
	path[idx] = 0;
	backtrack(arr, path, len, idx + 1, sum, target);
}

int	main(int argc, char *argv[])
{
	if (argc < 2)
		return (1);
	int index = -1;
	int target = atoi(argv[1]);
	int len = argc - 2;
	int *arr = malloc(sizeof(int) * len);
	int *path = malloc(sizeof(int) * len);
	if (!arr || !path)
		return (1);
	while (++index < len)
		arr[index] = atoi(argv[index + 2]);

	backtrack(arr, path, len, 0, 0, target);
	free(arr);
	free(path);
	return (0);
}
