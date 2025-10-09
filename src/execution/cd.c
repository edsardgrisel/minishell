/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrisel <egrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:49:04 by egrisel           #+#    #+#             */
/*   Updated: 2025/09/24 12:41:16 by egrisel          ###   ########.fr       */
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
	char	*cmd_str;
	int		len;

	cmd_str = ast_node->cmd_str;
	len = ft_strlen(cmd_str);
	if (len == 2)
	{
		// if (chrdir(get_env("HOME")) );
	}
	else
	{
		if (chdir(&(cmd_str[3])) == -1)
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