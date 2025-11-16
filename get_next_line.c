#include <stdio.h>
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static int	i = 0;
	int	j;
	char *buf;

	j = 0;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (i < BUFFER_SIZE && buf[j] != '\n')
	{
		read(fd, &buf[j], 1);
		i++;
		j++;
	}
	buf[j] = '\0';
	j++;
	return (buf);
}
