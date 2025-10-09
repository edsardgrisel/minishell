/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvan-ast <jvan-ast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 15:40:03 by jvan-ast          #+#    #+#             */
/*   Updated: 2025/10/09 17:48:51 by jvan-ast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <unistd.h>
# include "minishell.h"

void	set_stdin(char *txtfile);
void	set_stdout_trunc(char *txtfile);
void	execute_program(char **command, char *envp[]);
void	pipex(char *command[], int fd_pipe[2], int end, char *envp[]);
void 	pipex_test(t_ast_node *nodes, int write, int listen, char *envp[]);

#endif
