/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpassos- <bpassos-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 01:55:17 by charlie           #+#    #+#             */
/*   Updated: 2026/08/28 21:55:37 by bpassos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
// #include <stdio.h>

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		read_size;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = NULL;
	while (LOOP)
	{
		if (!*buffer)
		{
			read_size = read(fd, buffer, BUFFER_SIZE);
			if (read_size < 0)
				return (free(line), NULL);
			if (!read_size)
				return (line);
			buffer[read_size] = 0;
		}
		line = join_line(line, buffer);
		update_buffer(buffer);
		if (find_new_line(line))
			break ;
	}
	return (line);
}

// int	main(void)
// {
// 	int fd = open("file.txt", O_RDONLY | O_CREAT);
// 	// int fd = 5555;
// 	char *line;

// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		printf("[line]%s", line);
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	// line = get_next_line(fd);
// 	// printf("[line-break?]%s", line);
// 	// free(line);
// 	close(fd);
// }