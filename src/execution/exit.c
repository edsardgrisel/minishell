/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrisel <egrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 13:13:57 by egrisel           #+#    #+#             */
/*   Updated: 2025/10/09 16:13:28 by egrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <stdlib.h>

void	exit_cleanup(t_minishell_info *minishell_info)
{
	free_ast(minishell_info->ast);
}

/// @brief Will execute exit command and exit with exit status of previous cmd
/// if no arg provided and will exit with exit status of param if it is provided
/// between (0-255). If larger than 255, exit status is status % 255
/// CHECK EDGE CASES with too many args and invalid args
/// @param ast_node exit command node
/// @param minishell_info 
void	exec_exit(t_ast_node *ast_node, t_minishell_info *minishell_info)
{
	char	**cmd_list;
	int		exit_code;

	exit_code = 0;
	cmd_list = ast_node->cmd_list;
	// potential out of bounds error?
	if (cmd_list[1] == NULL)
	{
		exit_code = minishell_info->cur_exit_code;
	}
	else
	{
		// todo: what to do when more than one arg?
		// check overflows here?
		exit_code = ft_atoi(cmd_list[1]);
		// if atoi error do
	}
	exit_cleanup(minishell_info);
	exit(exit_code);
}
