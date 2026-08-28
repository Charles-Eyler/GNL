/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpassos- <bpassos-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 01:55:17 by charlie           #+#    #+#             */
/*   Updated: 2026/08/28 05:42:36 by bpassos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	size_t		read_size;
	
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = NULL;
	while (loop)
	{
		if (!*buffer)
		{
			read_size = read(fd, buffer, BUFFER_SIZE);
			if (read_size < 0)
				return (free(line), NULL);
		}
		line = join_line(line, buffer);
		update_buffer(buffer);
		if (find_new_line(line))
			break;
	}
	return (line);
}
int	main(void)
{
	
}