/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 08:43:10 by dlanehar          #+#    #+#             */
/*   Updated: 2025/11/26 10:21:08 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	char	*next_line;
	int		fd;

	fd = open("text.txt", O_RDONLY);
	if (fd == -1)
	{
		write(2, "Error reading file.\n", 20);
		return (-1);
	}
	while (1)
	{
		next_line = get_next_line(fd);
		printf("%s", next_line);
		if (!next_line)
		{
			free(next_line);
			break ;
		}
		free(next_line);
	}
	close(fd);
	return (0);
}
