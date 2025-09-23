/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrisel <egrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 13:13:57 by egrisel           #+#    #+#             */
/*   Updated: 2025/09/22 16:09:43 by egrisel          ###   ########.fr       */
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
	char	*command_and_args;
	int		len;
	int		exit_code;

	exit_code = 0;
	command_and_args = ast_node->command_and_args;
	len = ft_strlen(command_and_args);
	if (len == 4)
	{
		exit_code = minishell_info->cur_exit_code;
	}
	else if (len > 5)
	{
		// check overflows here?
		exit_code = ft_atoi(&(command_and_args[5]));
		// if atoi error do
	}
	exit_cleanup(minishell_info);
	exit(exit_code);
}
