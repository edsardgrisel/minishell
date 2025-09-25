/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stdout.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvan-ast <jvan-ast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 12:17:13 by jvan-ast          #+#    #+#             */
/*   Updated: 2025/09/25 15:54:50 by jvan-ast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	set_stdout_trunc(char *txtfile)
{
	int	fd;

	fd = open(txtfile, O_CREAT | O_WRONLY | O_TRUNC, 0666);
	if (fd == -1)
	{
		perror(txtfile);
		// exit(errno);
	}
	if (dup2(fd, 1) == -1)
	{
		perror("dup2 failed");
		// exit(errno);
	}
	if (close(fd) == -1)
	{
		perror(txtfile);
		// exit(errno);
	}
}
