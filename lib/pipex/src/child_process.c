/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvan-ast <jvan-ast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 14:54:42 by jvan-ast          #+#    #+#             */
/*   Updated: 2025/10/09 18:19:46 by jvan-ast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "helpers.h"
#include <unistd.h>
#include "minishell.h"
#include <stdio.h>

// static void	cleanup(void)
// {
// 	while (waitpid(-1, NULL, 0) > 0)
// 		;
// }
void close_all_pipes(t_ast_node *nodes)
{
	if (nodes == NULL)
		return ;
	close(nodes->fd[0]);
	close(nodes->fd[1]);
	close_all_pipes(nodes->parent);
}

static void create_child(t_ast_node *nodes, int fd_write, int fd_listen, char *envp[])
{
	int	pid;

	pid = fork();
	if (pid_ok(pid))
	{
		listen_pipe(fd_listen);
		write_pipe(fd_write);
		if (fd_write != 1)
			close(fd_write);
		if (fd_listen != 0)
			close(fd_listen);
		close_all_pipes(nodes);
		execute_program(nodes->cmd_list, envp);
	}
}

void pipex_test(t_ast_node *nodes, int write_fd, int listen_fd, char *envp[])
{
	int fd[2];
	
	if (nodes->node_type == NODE_CMD)
	{	
		printf("Write port: %d\nListen_port: %d\n", write_fd, listen_fd);
		fflush(stdout);
		create_child(nodes, write_fd, listen_fd, envp);
		return ;
	}
	else if (nodes->node_type == NODE_PIPE)
	{
		pipe(fd);
	}
	pipex_test(nodes->left, fd[1], listen_fd, envp);
	pipex_test(nodes->right, write_fd, fd[0], envp);
	return ;
}