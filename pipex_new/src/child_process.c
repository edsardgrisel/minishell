/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvan-ast <jvan-ast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 14:54:42 by jvan-ast          #+#    #+#             */
/*   Updated: 2025/09/26 12:42:49 by jvan-ast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "helpers.h"

static void	close_until(int fd[][2], int pipes, int until)
{
	int	i;

	i = 0;
	while (i <= until && i < pipes)
	{
		if (close(fd[i][0]) == -1)
			perror("Child close error");
		if (close(fd[i][1]) == -1)
			perror("Child close error");
		i++;
	}
	free(fd);
}

static void	close_fds(int fd[][2], int pipes)
{
	int	i;

	i = 0;
	while (i < pipes)
	{
		if (close(fd[i][0]) == -1)
			perror("Child close error");
		if (close(fd[i][1]) == -1)
			perror("Child close error");
		i++;
	}
	free(fd);
}

static void	cleanup(int fd[][2], int pipes)
{
	close_fds(fd, pipes);
	while (waitpid(-1, NULL, 0) > 0)
		;
}

void create_child(char *command, int fd_write, int fd_listen, char *envp[])
{
	int					pid;

	pid = fork();
	if (pid_ok(pid))
		{
			listen_pipe(fd_listen);
			write_pipe(fd_write);
			close(fd_write);
			close(fd_listen);
			execute_program(command, envp);
		}
}

void	pipex(char *command[], int fd_pipe[2], char *envp[])
{
	int					next_fd[2];
	int					pid;
	unsigned int		i;

	i = 0;
	
	pipe(next_fd);
	create_child(command[i], next_fd[1], fd_pipe[0], envp);
	close(fd_pipe[0]);
	close(next_fd[1]);
	fd_pipe[0] = next_fd[0];
	pipex(command+1, fd_pipe, envp);
}