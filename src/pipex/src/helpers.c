/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvan-ast <jvan-ast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 12:08:00 by jvan-ast          #+#    #+#             */
/*   Updated: 2025/09/29 09:58:03 by jvan-ast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	write_pipe(int fd[2])
{
	if (dup2(fd[1], STDOUT_FILENO) == -1)
	{
		perror("dup2");
		exit(errno);
	}
}

void	listen_pipe(int fd[2])
{
	if (dup2(fd[0], STDIN_FILENO) == -1)
	{
		perror("dup2");
		exit(errno);
	}
}

int	pid_ok(int pid)
{
	if (pid == -1)
	{
		perror("Fork");
	}
	if (pid == 0)
		return (1);
	return (0);
}
