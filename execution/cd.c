/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrisel <egrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:49:04 by egrisel           #+#    #+#             */
/*   Updated: 2025/09/22 16:33:52 by egrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <stdio.h>
#include <unistd.h>

/// @brief If command is only "cd" go to home, if abs or relative path pass to
/// chdir. "-" and "~" can be added is needed.
/// @param ast_node 
/// @param minishell_info 
void	exec_cd(t_ast_node *ast_node, t_minishell_info *minishell_info)
{
	char	*command_and_args;
	int		len;

	command_and_args = ast_node->command_and_args;
	len = ft_strlen(command_and_args);
	if (len == 2)
	{
		// if (chrdir(get_env("HOME")) );
	}
	else
	{
		if (chdir(&(command_and_args[3])) == -1)
		{
			perror("cd");
			minishell_info->cur_exit_code = 1;
			return ;
		}
		else
		{
			minishell_info->cur_exit_code = 0;
		}
	}
}