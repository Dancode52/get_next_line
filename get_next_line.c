#include "get_next_line.h"
#include <stdio.h>

// void	place_in_temp(char *buf, char *store, ssize_t readsize)
// {
// 	buf[readsize] = '\0';
// 	store = ft_strjoin(store, buf);
// 	free(buf);
// }

char	*extract_up_to_newline(char *store)
{
	int	len;
//	int i;
	char	*res;

	len = 0;
//	i = 0;
	while (store[len] != '\n')
		len++;
	len++;
	res = ft_substr(store, 0, len + 1);
	// res = malloc(len + 1);
	if (!res)
	 	return (NULL);
	// while (i < len)
	// {
	// 	res[i] = store[i];
	// 	i++;
	// }
//	res[len] = '\n';
	res[len] = '\0';
	return (res);
}

char *get_next_line(int fd)
{
	static char	*store;
	char		*buf;
	char		*newline;
	ssize_t			readsize;
	int	i;

	while (1)
	{
		buf = (char *)malloc(1 * BUFFER_SIZE + 1);
		if (!buf)
			return (NULL);
		readsize = read(fd, buf, BUFFER_SIZE);
		if (readsize == -1)
			return (NULL);
		if (readsize == 0)
			return (NULL);
		buf[readsize] = '\0';
		//store = ft_substr(buf, 0, readsize);
		store = ft_strjoin(store, buf);
		free(buf);
		if (ft_memchr(store, '\n', ft_strlen(store)))
		{
			newline = extract_up_to_newline(store);
			i = ft_strlen(newline);
			store = ft_substr(store, i, BUFFER_SIZE + 1);
			// printf("%s", store);
			return (newline);
		}
	}
	free(store);
	return (NULL);
//	newline = ft_strdup(store);
// 	free(store);
// 	return (newline);
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
