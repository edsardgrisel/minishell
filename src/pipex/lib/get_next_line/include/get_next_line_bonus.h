/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvan-ast <jvan-ast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 13:14:26 by jvan-ast          #+#    #+#             */
/*   Updated: 2025/09/05 19:31:48 by jvan-ast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

// Macro to define the buffer size of the read function.
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100000
# endif

// Macro to define the maximum amount of file descriptors
# ifndef MAX_FD
#  define MAX_FD 1024
# endif

int		str_len(char *str);
void	strn_copy(char *src, char *dest, int n);
char	*find_trim(char *tracking_buffer);
int		search_last_buffer(char **tracking_buffer, char **line);
int		buffer_concat(char *new_read, char **tracking_buffer);
char	*get_next_line(int fd);

#endif