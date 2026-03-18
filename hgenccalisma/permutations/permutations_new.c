#include <unistd.h>

void	ft_sort(char *s, int len)
{
	int		i;
	int		j;
	char	tmp;

	i = -1;
	while (++i < len - 1)
	{
		j = -1;
		while (++j < len - 1 - i)
		{
			if (s[j] > s[j + 1])
			{
				tmp = s[j];
				s[j] = s[j + 1];
				s[j + 1] = tmp;
			}
		}
	}
}

void	backtrack(char *s, char *buf, int *used, int depth, int len)
{
	int	i;

	if (depth == len)
	{
		write(1, buf, len);
		write(1, "\n", 1);
		return ;
	}
	i = -1;
	while (++i < len)
	{
		if (!used[i])
		{
			used[i] = 1;
			buf[depth] = s[i];
			backtrack(s, buf, used, depth + 1, len);
			used[i] = 0;
		}
	}
}

int	main(int ac, char **av)
{
	char	s[1024];
	char	buf[1024];
	int		used[1024];
	int		len;
	int		i;

	if (ac != 2)
		return (1);
	len = 0;
	while (av[1][len])
	{
		s[len] = av[1][len];
		len++;
	}
	s[len] = '\0';
	i = -1;
	while (++i < len)
		used[i] = 0;
	ft_sort(s, len);
	backtrack(s, buf, used, 0, len);
	return (0);
}
