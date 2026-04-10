
#include "repaired_simple.h"

char *get_next_line(int fd)
{
	static char buf[999999];
	static ssize_t bytes = 0;
	static ssize_t i = 0;
	ssize_t j = 0;
	
	char *line = malloc(10000);
	if (!line || fd < 0)
		return NULL;

	while (1)
	{
		if (i >= bytes)
		{
			i = 0;
			bytes = read(fd, buf, BUFFER_SIZE);
			if (bytes <= 0)
				break;
		}
		line[j] = buf[i++];
		if (line[j++] == '\n')
			break;
	}
	if (!j)
		return (free(line), NULL);
	line[j] = '\0';
	return line;
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