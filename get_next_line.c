#include "get_next_line.h"
#include <stdio.h>

char	*fill_storage(char *buf, char *store, int fd)
{
	ssize_t	readchars;
	char	*tmp;

	readchars = 1;
	while (readchars > 0)
	{
		readchars = read(fd, buf, BUFFER_SIZE);
		buf[readchars] = '\0';
		if (readchars == - 1)
		{
			free(store);
			free(buf);
			return (NULL);
		}
		if (readchars == 0 && (store[0] == 0))
		{
			free(buf);
			return (NULL);
		}
		tmp = ft_strjoin(store, buf);
		if (!tmp)
			return (NULL);
		free(store);
		store = tmp;
		if (ft_strchr(store, '\n'))
			break;
	}
	return (store);
}

char	*new_line_trunc(char *newline)
{
	ssize_t	i;
	char *tmp;

	i = 0;
	if (!newline)
		return (NULL);
	while (newline[i] && newline[i] != '\n')
		i++;
	tmp = ft_substr(newline, i + 1, ft_strlen(newline) - (i + 1));
	newline[i + 1] = '\0';
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*store;
	char		*buf;
	char		*newline;

	buf = (char *)malloc(BUFFER_SIZE + 1);
	newline = fill_storage(buf, store, fd);
	free(buf);
	if (!newline)
		return (NULL);
	store = new_line_trunc(newline);
	return (newline);
}
// char	*extract_up_to_newline(char *store)
// {
// 	int	len;
// 	char	*res;

// 	len = 0;
// 	while (store[len] != '\n')
// 		len++;
// 	len++;
// 	res = ft_substr(store, 0, len + 1);
// 	if (!res)
// 	 	return (NULL);
// 	res[len] = '\0';
// 	return (res);
// }

// {
// 	static char	*store;
// 	char		*buf;
// 	char		*newline;
// 	ssize_t			readsize;
// 	int	i;

// 	while (1)
// 	{
// 		buf = (char *)malloc(1 * BUFFER_SIZE + 1);
// 		if (!buf)
// 			return (NULL);
// 		readsize = read(fd, buf, BUFFER_SIZE);
// 		buf[readsize] = '\0';
// 		if (store)
// 		{
// 			while (readsize == 0 && ft_memchr(store, '\n', ft_strlen(store)))
// 				{
// 					if (ft_memchr(store, '\n', ft_strlen(store)))
// 						{
// 							newline = extract_up_to_newline(store);
// 							i = ft_strlen(newline);
// 							store = ft_substr(store, i, BUFFER_SIZE + 1);
// 							free(buf);
// 							return (newline);
// 						}
// 				}
// 		}
// 		if (readsize == -1)
// 			return (NULL);
// 		if (readsize == 0)
// 			return (NULL);
// 		store = ft_strjoin(store, buf);
// 		free(buf);
// 		if (ft_memchr(store, '\n', ft_strlen(store)))
// 		{
// 			newline = extract_up_to_newline(store);
// 			i = ft_strlen(newline);
// 			store = ft_substr(store, i, BUFFER_SIZE + 1);
// 			return (newline);
// 		}
// 	}
// 	free(store);
// 	return (NULL);
// }

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
