#include <unistd.h>


void	ft_swap(char *a, char *b)
{
	char tmp = *a;
	*a = *b;
	*b = tmp;
}

int	ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_sort(char *str, int len)
{
	int i = 0;
	while (i < len - 1)
	{
		int j = 0;
		while (j < len - 1 - i)
		{
			if (str[j] > str[j + 1])
				ft_swap(&str[j], &str[j + 1]);
			j++;
		}
		i++;
	}
}

int	next_permutation(char *str, int len)
{
	int i = len - 2;
	while (i >= 0 && str[i] >= str[i + 1])
		i--;
	if (i < 0)
		return (0);
	int j = len - 1;
	while (str[j] <= str[i])
		j--;
	ft_swap(&str[i], &str[j]);
	int left = i + 1;
	int right = len - 1;
	while (left < right)
	{
		ft_swap(&str[left], &str[right]);
		left++;
		right--;
	}
	return (1);
}

int	main(int ac, char **av)
{
	int i = -1;
	char s[1024];
	if (ac != 2)
		return (1);

	while (av[1][++i])
		s[i] = av[1][i];

	s[i] = '\0';
	int len = ft_strlen(s);
	ft_sort(s, len);
	write(1, s, len);
	write(1, "\n", 1);
	while (next_permutation(s, len))
	{
		write(1, s, len);
		write(1, "\n", 1);
	}
	return (0);
}
