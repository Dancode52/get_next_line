/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 08:43:10 by dlanehar          #+#    #+#             */
/*   Updated: 2025/11/21 14:37:25 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
// #include <stdio.h>
// #include "get_next_line.h"

// int main()
// {
// 	char *res;
// 	int	fd;
// 	int	i;

// 	fd = open("text.txt", O_RDONLY);
// 	i = 0;
// 	while (i < 1)
// 	{
// 		res = get_next_line(fd);
// 		printf("%s", res);
// 		free(res);
// 		i++;
// 	}
// 	return (0);
// }

#include "get_next_line.h"
#include <stdio.h>

int    main(int ac, char **av)
{
    char    *next_line;
    int        fd;
	int i;
	(void)ac;
	(void)av;

	i = 0;
 	fd = open("text.txt", O_RDONLY);
    if (fd == -1)
    {
        write(2, "Error reading file.\n", 20);
        return (-1);
    }
    //close(fd);
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
		i++;
    }
    close(fd);
    return (0);
}

// int	main()
// {
// 	int fd;
// 	char* out;

// 	fd = open("text.txt", O_RDONLY);
// 	out = get_next_line(fd);
// 	printf("%s", out);
// 	free(out);
// }
