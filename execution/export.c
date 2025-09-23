/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrisel <egrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:30:05 by egrisel           #+#    #+#             */
/*   Updated: 2025/09/23 15:00:57 by egrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <unistd.h>

void	export_no_args(char **envp)
{
	int		i;
	int		j;
	int		left_len;

	i = 0;
	while (envp[i])
	{
		j = 0;
		while (envp[i][j])
		{
			if (envp[i][j] == '=')
			{
				left_len = j + 1;
				break;
			}
			j++;
		}
		write(1, "declare -x ", 11);
		write(1, envp[i], left_len);
		write(1, "\"", 1);
		write(1, &(envp[i][left_len]), ft_strlen(&(envp[i][left_len])));
		write(1, "\"\n", 2);
		i++;
	}
}

/// @brief 
/// check if strncmp is safe here
/// @param ast_node 
/// @param minishell_info 
void	exec_export(t_ast_node *ast_node, t_minishell_info *minishell_info)
{
	char	*command_and_args;
	
	command_and_args = ast_node->command_and_args;
	if (ft_strncmp(command_and_args, "export", 6) == 0)
		export_no_args(*(minishell_info->envp));
	
}