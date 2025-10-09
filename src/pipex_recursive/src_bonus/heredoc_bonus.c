/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvan-ast <jvan-ast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 14:00:10 by jvan-ast          #+#    #+#             */
/*   Updated: 2025/09/18 18:22:06 by jvan-ast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "pipex_bonus.h"

static void	unlink_tmp_file(char *txtfile)
{
	int	tmp_file;

	tmp_file = open(txtfile, O_RDONLY, 0600);
	if (tmp_file == -1)
	{
		perror(txtfile);
		return ;
	}
	if (dup2(tmp_file, 0) == -1)
	{
		perror("dup2 tmp failed");
	}
	if (unlink(txtfile) == -1)
	{
		perror("Failed to unlink tmp file");
	}
	if (close(tmp_file) == -1)
	{
		perror(txtfile);
	}
}

static void	write_heredoc(int fd, char *limiter)
{
	char	*buffer;

	while (1)
	{
		write(1, "heredoc> ", 9);
		buffer = get_next_line(0);
		if (buffer == NULL)
		{
			write(2, "\nwarning: here-document delimited by end-of-file\n", 49);
			break ;
		}
		if (ft_strncmp(buffer, limiter, ft_strlen(limiter)) == 0)
		{
			free(buffer);
			break ;
		}
		if (write(fd, buffer, ft_strlen(buffer)) == -1)
			perror("Write error");
		free(buffer);
	}
}

void	create_heredoc(char *limiter)
{
	int		fd;
	char	*txtfile;

	txtfile = ".heredoc_tmp";
	limiter = ft_strjoin(limiter, "\n");
	if (limiter == NULL)
	{
		perror("Malloc fail");
		exit(errno);
	}
	fd = open(txtfile, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fd == -1)
		return (perror("open here_doc_tmp failed"), free(limiter));
	write_heredoc(fd, limiter);
	free(limiter);
	if (close(fd) == -1)
	{
		perror(txtfile);
		exit(errno);
	}
	unlink_tmp_file(txtfile);
}

void	set_stdout_end(char *txtfile)
{
	int	fd;

	fd = open(txtfile, O_APPEND | O_CREAT | O_WRONLY, 0644);
	if (fd == -1)
	{
		perror(txtfile);
		exit(errno);
	}
	if (dup2(fd, 1) == -1)
	{
		perror("dup2 failed");
		exit(errno);
	}
	if (close(fd) == -1)
	{
		perror(txtfile);
	}
}
