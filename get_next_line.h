/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpassos- <bpassos-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 01:55:09 by charlie           #+#    #+#             */
/*   Updated: 2026/08/28 05:42:29 by bpassos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42

#endif

# define loop 1

char	*find_new_line (char *line);
size_t	line_len_gnl(char	*line);
void	*ft_memcpy(void *dest, const void *src, size_t nbytes);
char	*join_line(char	*line, char *buffer);
void	update_buffer(char	*buffer);

#endif