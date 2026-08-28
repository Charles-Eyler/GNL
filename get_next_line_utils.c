/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpassos- <bpassos-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 01:55:20 by charlie           #+#    #+#             */
/*   Updated: 2026/08/28 16:58:27 by bpassos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

bool	find_new_line (char *line)
{
	if (!line)
		return (NOT_FOUND);
	while (*line)
	{
		if (*line == '\n')
			return (FOUND);
		line++;
	}
	return (NOT_FOUND);
}

size_t	line_len_gnl(char	*line)
{
	int	len;

	len = 0;
	if (!line)
		return (0);
	while (line[len] && line[len] != '\n')
		len++;
	if (line[len] == '\n')
		len++;
	return (len);
}

void	*ft_memcpy(void *dest, const void *src, size_t nbytes)
{
	u_char			*temp_dest;
	const u_char	*temp_src;
	size_t			i;

	temp_dest = dest;
	temp_src = src;
	i = 0;
	while (i < nbytes)
	{
		temp_dest[i] = temp_src[i];
		i++;
	}
	return (dest);
}
char	*join_line(char	*line, char *buffer)
{
	int		line_len;
	int		buffer_len;
	char	*new;

	if (!buffer)
		return (line);
	line_len = line_len_gnl(line);
	buffer_len = line_len_gnl(buffer);
	new = malloc(line_len + buffer_len + 1);
	if (!new)
		return (NULL);
	if (line)
		ft_memcpy(&new[0], line, line_len);
	ft_memcpy(&new[line_len], buffer, buffer_len);
	new[line_len + buffer_len] = '\0';
	free(line);
	return (new);
}
void	update_buffer(char	*buffer)
{
	size_t	new_start;
	size_t	i;

	new_start = line_len_gnl(buffer);
	i = 0;
	if (!new_start)
		return ;
	while (buffer[new_start + i])
	{
		buffer[i] = buffer[new_start + i];
		i++;
	}
	buffer[i] = '\0';
}