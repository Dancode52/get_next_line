#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char	*store;
	char		*buf;
	char		*newline;
	int			readsize;

	readsize = -1;
	while (readsize != 0)
	{
		buf = (char *)malloc(1 * BUFFER_SIZE + 1);
		readsize = read(fd, buf, BUFFER_SIZE);
		buf[readsize] = '\0';
		store = ft_strjoin(store, buf);
		free(buf);
	}
	newline = ft_strdup(store);
	free(store);
	return (newline);
}
// 	static char	*store;
// 	char		*tmp;
// 	char		*buf;
// 	char		*newline;
// 	int			len;

// 	store = NULL;
// 	buf = NULL;
// 	tmp = NULL;
// 	while (1)
// 	{
// 		buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
// 			if (!buf)
// 				return (NULL);
// 		len = read(fd, buf, BUFFER_SIZE);
// //		buf[BUFFER_SIZE + 1] = '\0';
// 		tmp = ft_strjoin(store, buf);
// 		free(store);
// 		store = tmp;
// 		free(tmp);
// 		if (len == 0)
// 			return (NULL);
// 		if (ft_memchr(store, '\n', ft_strlen(store)))
// 		{
// 			len = ft_strlen(store) - ft_strlen((ft_memchr(store, '\n', ft_strlen(store))));
// 			newline = malloc(len + 2);
// 			newline = ft_memcpy(newline, store, len + 1);
// 			newline[len + 1] = '\0';
// 			store = store + len + 1;
// 			return (newline);
// 		}
// 		free(buf);
// 	}
// 	return (NULL);
