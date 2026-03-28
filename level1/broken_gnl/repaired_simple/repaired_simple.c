
#include "repaired_simple.h"

char	*get_next_line(int fd)
{
	static char		buf[BUFFER_SIZE];
	static ssize_t	bytes;
	static int		i;
	char			*line;
	int				j;

	line = malloc(10000);
	if (!line || fd < 0)
		return (NULL);
	j = 0;
	while (1)
	{
		if (i >= bytes)
		{
			i = 0;
			bytes = read(fd, buf, BUFFER_SIZE);
			if (bytes <= 0)
				break ;
		}
		line[j] = buf[i++];
		if (line[j++] == '\n')
			break ;
	}
	if (!j)
		return (free(line), NULL);
	line[j] = 0;
	return (line);
}
/*
int	main(void)
{
	char *s;
	while((s=get_next_line(0)))
	{
		printf("%s", s);
	}
}*/