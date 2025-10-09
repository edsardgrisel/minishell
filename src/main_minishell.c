/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvan-ast <jvan-ast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 14:41:53 by egrisel           #+#    #+#             */
/*   Updated: 2025/10/09 17:44:27 by jvan-ast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>
#include "pipex.h"

/// @brief Loops and calls minishell repeatedly. if -1 returned, return
/// current exit code. It is the reponsability of minishell() to perror the
/// reason
/// @param argc 
/// @param argv 
/// @param envp 
/// @return 
int	main(int argc, char *argv[], char *envp[])
{
	t_minishell_info	minishell_info;
	
	(void)argc;
	(void)argv;
	minishell_info.envp = &envp;
	minishell_info.cur_exit_code = 0;
	while (1)
	{
		if (minishell(&minishell_info) == -1)
		{
			return (minishell_info.cur_exit_code);
		}
	}
}