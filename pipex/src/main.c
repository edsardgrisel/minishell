/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvan-ast <jvan-ast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 12:30:55 by jvan-ast          #+#    #+#             */
/*   Updated: 2025/09/24 10:56:47 by jvan-ast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	char	*err_mss;

	if (argc != 5)
	{
		err_mss = "Follow the correct format:\n./pipex file1 cmd1 cmd2 file2\n";
		write(2, err_mss, ft_strlen(err_mss));
		exit(EXIT_FAILURE); // exit(127)
	}
	set_stdin(argv[1]);
	set_stdout_trunc(argv[argc - 1]);
	argv += 2;
	argc -= 3;
	if (argc > 0)
		pipex(argc, argv, envp);
	exit(EXIT_SUCCESS);
}
