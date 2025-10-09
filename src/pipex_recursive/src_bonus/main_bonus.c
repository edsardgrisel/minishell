/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvan-ast <jvan-ast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 14:50:39 by jvan-ast          #+#    #+#             */
/*   Updated: 2025/09/18 18:21:12 by jvan-ast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "pipex_bonus.h"

int	main(int argc, char *argv[], char *envp[])
{
	char	*err_mss;

	if (argc > 3 && !ft_strncmp(argv[1], "here_doc", 8))
	{
		create_heredoc(argv[2]);
		set_stdout_end(argv[argc - 1]);
		argc -= 4;
		argv += 3;
	}
	else if (argc > 3)
	{
		set_stdout_trunc(argv[argc - 1]);
		set_stdin(argv[1]);
		argv += 2;
		argc -= 3;
	}
	else
	{
		err_mss = "Error:\n./pipex_bonus here_doc LIMITER cmd ... cmd_n file\n";
		write(2, err_mss, ft_strlen(err_mss));
		exit(EXIT_FAILURE);
	}
	pipex(argc, argv, envp);
	exit (EXIT_SUCCESS);
}
