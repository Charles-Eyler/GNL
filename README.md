*This project has been created as part
of the 42 curriculum by bpassos-.*

# Description

get_next_line is a 42 project that aims to create a function that is able to read a file (text file, file descriptor, etc...) and return only a single line at the time.

The functions reads from the given file descriptor using a static buffer that is defined during the compilation process by the user. This static buffer is recalled until it finds a new line (character '\n').The function returns the line that was read including the trailling \n everytime the function is called.

### get_next_line prototype

```c
char *get_next_line(int fd);
```

# Instructions

### Compilation

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=[number] get_next_line.c get_next_line_utils.c
```
During compilation the user is able to define the buffer directly by insertinf the "-D" flag followed by "BUFFER_SIZE=" followed by the number of bytes that it will read at the time.

### Usage

to test this function, create a file called file.txt and use the main below to see every line in a loop until the end of the file.

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int fd = open("file.txt", O_RDONLY);
	char *line;

	while ((line = get_next_line(fd)) != NULL)
	{
		printf("[line]%s", line);
		free(line);
	}
	close(fd);
}
```
- Note:
The user is the one responsible for freeing the memory that was allocated by get_next_line.

### Return Values

| Return | Meaning |
|--------|---------|
| `char *` | the line that was read, including `\n` |
| `NULL` | nothing left to read or an error occurred |

# Algorithm

Get_next_line works by allocating the memory that has read on a "stack" until it reaches '\n'. This is done by saving the buffer content into a string and then moving the position of the buffer.

### 1st:  Reading...

First, read will used to read the file descriptor into the buffer. 

If the return value of read is negative, then an error occured, so we free line and return NULL.

If the return value is 0, then there's nothing else to be read, so we return line.

### 2nd: Getting the line

To retrive the line,  join_line uses the function line_len_gnl which is a reimplementation of strlen, that also increaments its count if it finds a '\n' to get the size that is needed to copy it to a new string, malloc'ing only what is needed for the return line.

### 3rd: Updating the buffer

After retriving the line, update_buffer moves everything after the newline to the start of the buffer.This is done to ensure that no data from the file that is read is lost. This could happen if the buffer was not move as any content after the new line character would be lost.

Otherwise, if no newline was found, buffer[0] is set to '\0' signalling an empty buffer.


# Resources

- https://www.youtube.com/watch?v=-Mt2FdJjVno
- 42 peers.