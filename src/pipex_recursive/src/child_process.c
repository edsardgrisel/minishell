/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvan-ast <jvan-ast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 14:54:42 by jvan-ast          #+#    #+#             */
/*   Updated: 2025/10/09 12:36:52 by jvan-ast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "helpers.h"
#include <unistd.h>


static void	cleanup(void)
{
	while (waitpid(-1, NULL, 0) > 0)
		;
}

void create_child(char *command, int next_pipe[2], int fd_listen, char *envp[])
{
	int					pid;

	
	pid = fork();
	if (pid_ok(pid))
	{
		listen_pipe(fd_listen);
		write_pipe(next_pipe[1]);
		if (next_pipe[1] != 1)
			close(next_pipe[1]);
		if (fd_listen != 0)
			close(fd_listen);
		close(next_pipe[0]);
		execute_program(command, envp);
	}
}

void	pipex(char *command[], int fd_pipe[2], int end, char *envp[])
{
	int		next_fd[2];

	if (end != 1)
	{
		pipe(next_fd);
		create_child(command[0], next_fd, fd_pipe[0], envp);
		close(fd_pipe[0]);
		close(next_fd[1]);
		fd_pipe[0] = next_fd[0];
		pipex(command->next, fd_pipe, end - 1, envp);
		exit(0);
	}
	create_child(command[0], fd_pipe, fd_pipe[0], envp);
	close(fd_pipe[0]);
	close(fd_pipe[1]);
	cleanup();
}