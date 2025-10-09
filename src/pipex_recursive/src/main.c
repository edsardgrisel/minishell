/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvan-ast <jvan-ast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 12:30:55 by jvan-ast          #+#    #+#             */
/*   Updated: 2025/09/26 13:16:18 by jvan-ast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <unistd.h>
#include <stdio.h>

int	main(int argc, char *argv[], char *envp[])
{
	int fd[2];

	fd[0] = STDIN_FILENO;
	fd[1] = STDOUT_FILENO;
	
	// envp = 0;
	// argc = 0;
	pipex(argv + 1, fd, argc - 1, envp);
	exit(EXIT_SUCCESS);
}
