/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvan-ast <jvan-ast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 12:08:00 by jvan-ast          #+#    #+#             */
/*   Updated: 2025/09/26 13:23:50 by jvan-ast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	write_pipe(int fd, char *program)
{
	if (dup2(fd, STDOUT_FILENO) == -1)
	{
		perror(program);
		exit(errno);
	}
}

void	listen_pipe(int fd, char *program)
{
	if (dup2(fd, STDIN_FILENO) == -1)
	{
		perror(program);
		exit(errno);
	}
}

int	pid_ok(int pid)
{
	if (pid == -1)
	{
		perror("Fork");
		exit(errno);
	}
	if (pid == 0)
		return (1);
	return (0);
}
