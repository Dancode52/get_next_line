/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 08:56:50 by dlanehar          #+#    #+#             */
/*   Updated: 2025/12/10 12:56:17 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*fill_storage(char *buf, char **store, int fd)
{
	ssize_t	readchars;
	char	*tmp;

	readchars = 1;
	while (readchars > 0)
	{
		readchars = read(fd, buf, BUFFER_SIZE);
		if (readchars == -1 || (*store && (readchars == 0 && ((*store)[0] == 0)
			)) || (readchars == 0 && *store == NULL))
		{
			free(*store);
			*store = NULL;
			return (NULL);
		}
		buf[readchars] = '\0';
		tmp = ft_strjoin(*store, buf);
		if (!tmp)
			return (NULL);
		if (*store)
			free(*store);
		*store = tmp;
		if (ft_strchr(*store, '\n'))
			break ;
	}
	return (*store);
}

char	*new_line_trunc(char *newline)
{
	ssize_t	i;
	char	*tmp;

	i = 0;
	if (!newline)
		return (NULL);
	while (newline[i] && newline[i] != '\n')
		i++;
	tmp = ft_substr(newline, i + 1, ft_strlen(newline) - (i + 1));
	if (newline[i] == '\n')
		newline[i + 1] = '\0';
	else
		newline[i] = '\0';
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*store;
	char		*buf;
	char		*newline;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (store != NULL)
			free (store);
		store = NULL;
		return (NULL);
	}
	buf = (char *)malloc((size_t)BUFFER_SIZE + 1);
	newline = fill_storage(buf, &store, fd);
	free(buf);
	if (!newline)
		return (NULL);
	store = new_line_trunc(newline);
	return (newline);
}
