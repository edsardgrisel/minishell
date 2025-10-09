/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stdin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvan-ast <jvan-ast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 12:17:28 by jvan-ast          #+#    #+#             */
/*   Updated: 2025/09/22 10:59:14 by jvan-ast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	set_stdin(char *txtfile)
{
	int	fd;

	fd = open(txtfile, O_RDONLY);
	if (fd == -1)
	{
		perror(txtfile);
		return ;
	}
	if (dup2(fd, 0) == -1)
	{
		perror("dup2 failed");
	}
	if (close(fd) == -1)
	{
		perror(txtfile);
	}
}
