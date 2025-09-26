/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvan-ast <jvan-ast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 18:42:50 by jvan-ast          #+#    #+#             */
/*   Updated: 2025/06/16 19:17:53 by jvan-ast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	strn_copy(char *src, char *dest, int n)
{
	int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

char	*find_trim(char *tracking_buffer)
{
	int	i;

	i = 0;
	if (!tracking_buffer)
		return (NULL);
	while (tracking_buffer[i] != '\n' && tracking_buffer[i])
		i++;
	if (tracking_buffer[i] == '\n')
		return (&tracking_buffer[i + 1]);
	return (NULL);
}

int	search_last_buffer(char **tracking_buffer, char **sentence)
{
	if (**tracking_buffer)
	{
		*sentence = malloc(str_len(*tracking_buffer) + 1);
		if (*sentence == NULL)
			return (EXIT_FAILURE);
		strn_copy(*tracking_buffer, *sentence, str_len(*tracking_buffer));
		free(*tracking_buffer);
		*tracking_buffer = NULL;
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

int	buffer_concat(char *new_read, char **tracking_buffer)
{
	char	*new_buffer;
	int		len_tracking_buffer;
	int		len_new_read;

	if (!(*tracking_buffer))
	{
		*tracking_buffer = new_read;
		return (EXIT_SUCCESS);
	}
	len_tracking_buffer = str_len(*tracking_buffer);
	len_new_read = str_len(new_read);
	new_buffer = malloc(len_tracking_buffer + len_new_read + 1);
	if (new_buffer == NULL)
		return (free(new_read), EXIT_FAILURE);
	strn_copy(*tracking_buffer, new_buffer, len_tracking_buffer);
	strn_copy(new_read, new_buffer + len_tracking_buffer, len_new_read);
	free(new_read);
	free(*tracking_buffer);
	*tracking_buffer = new_buffer;
	return (EXIT_SUCCESS);
}
