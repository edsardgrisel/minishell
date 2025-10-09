/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvan-ast <jvan-ast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 14:54:42 by jvan-ast          #+#    #+#             */
/*   Updated: 2025/09/26 11:52:59 by jvan-ast         ###   ########.fr       */
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

void	pipex(unsigned int num_commands, char *command[], char *envp[])
{
	int					(*fd)[2];
	int					pid;
	unsigned int		i;

	i = 0;
	fd = malloc(sizeof(int [num_commands - 1][2]));
	if (!fd)
		return (free(fd), perror("Malloc error 3"), exit(errno));
	while (i < num_commands)
	{
		if (i < num_commands - 1 && pipe(fd[i]) == -1)
			return (perror("pipe"), cleanup(fd, i), exit(errno));
		pid = fork();
		if (pid_ok(pid))
		{
			if (i > 0)
				listen_pipe(fd[i - 1]);
			if (i < num_commands - 1)
				write_pipe(fd[i]);
			close_until(fd, num_commands - 1, i);
			execute_program(command[i], envp);
		}
		i++;
	}
	cleanup(fd, num_commands - 1);
}
