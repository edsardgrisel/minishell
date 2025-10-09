/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvan-ast <jvan-ast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 13:14:42 by jvan-ast          #+#    #+#             */
/*   Updated: 2025/09/18 15:28:47 by jvan-ast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/* isolate_line
DESCRIPTION
The following function checks for a next line in the buffer. 
If a new line is found, the function adjust the line variable and 
trims the tracking variable (static).
RETURN VALUE 
returns 0 upon succesfull operation and 1 if anything goes wrong.
*/
static int	isolate_line(char **tracking_buffer, char **line)
{
	char		*trim_point;
	char		*new_buffer;

	if (*tracking_buffer == NULL)
		return (EXIT_SUCCESS);
	trim_point = find_trim(*tracking_buffer);
	if (trim_point)
	{
		*line = malloc(trim_point - *tracking_buffer + 1);
		new_buffer = malloc(str_len(trim_point) + 1);
		if (!*line || !new_buffer)
			return (free(*line), free(new_buffer), EXIT_FAILURE);
		strn_copy(*tracking_buffer, *line, trim_point - *tracking_buffer);
		strn_copy(trim_point, new_buffer, str_len(trim_point));
		free(*tracking_buffer);
		*tracking_buffer = new_buffer;
	}
	return (EXIT_SUCCESS);
}

/* read_to_tracking_buffer
DESCRIPTION
This function is responsible for concatenating a new read to the tracking buffer.
When the number read is 0 this means the end of the file is reached, 
and the next line will be the tracking buffer.
RETURN VALUE:
0 if read is done correctly, otherwise 1 will be returned.
If number read is 0 and tracking buffer is NULL, 1 is returned.
*/
static int	read_to_tracking_buffer(int fd, char **tracking_buffer, char **line)
{
	char	*new_read;
	int		num_read;

	new_read = malloc(BUFFER_SIZE + 1);
	if (new_read == NULL)
		return (EXIT_FAILURE);
	num_read = read(fd, new_read, BUFFER_SIZE);
	if (num_read == -1)
		return (free(new_read), EXIT_FAILURE);
	if (num_read == 0)
	{
		free(new_read);
		if (*tracking_buffer)
			return (search_last_buffer(tracking_buffer, line));
		return (EXIT_FAILURE);
	}
	new_read[num_read] = '\0';
	return (buffer_concat(new_read, tracking_buffer));
}

void	check_tracking_buffer(char **tracking_buffer)
{
	if (*tracking_buffer != NULL && **tracking_buffer == '\0')
	{
		free(*tracking_buffer);
		*tracking_buffer = NULL;
	}
}

/* 
get_next_line
DESCRIPTION
Recursive function retrieves the next line from the selected file descriptor. 
The following is done:
1. the tracking buffer is checked. (isolate_line)
2. Reading frame is  concatenated to tracking buffer (read_to_tracking_buffer)
This is done recursively until new line.

Upon reaching last line the tracking buffer is set to NULL;

RETURN VALUE:
The next line will be returned (char *), 
or NULL when an error occurs or the end of the file has been reached
IMPROVEMENT 
To improve this function different return values could be introduced. 
For the scope of this project, it is decided not to include this
*/
char	*get_next_line(int fd)
{
	static char	*tracking_buffer[MAX_FD] = {0};
	char		*line;

	line = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (isolate_line(&(tracking_buffer[fd]), &line))
	{
		free(tracking_buffer[fd]);
		tracking_buffer[fd] = NULL;
		return (NULL);
	}
	if (line)
		return (check_tracking_buffer(&(tracking_buffer[fd])), line);
	if (read_to_tracking_buffer(fd, &(tracking_buffer[fd]), &line))
	{
		free(tracking_buffer[fd]);
		tracking_buffer[fd] = NULL;
		return (NULL);
	}
	if (line)
		return (check_tracking_buffer(&(tracking_buffer[fd])), line);
	return (get_next_line(fd));
}
