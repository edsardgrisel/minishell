/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrisel <egrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 13:54:38 by egrisel           #+#    #+#             */
/*   Updated: 2025/09/11 14:08:33 by egrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>
#include <stdio.h>

/// @brief this function is only called when the ast_node->builtin_type is env.
/// If envp not null, print env variables
/// @param minishell_info 
void	exec_env(t_minishell_info *minishell_info)
{
	int	i;
	char	**envp;

	envp = *(minishell_info->envp);
	if (envp != NULL)
	{
		i = 0;
		while (envp[i])
		{
			printf("%s\n", envp[i]);
			i++;
		}
	}
	minishell_info->cur_exit_code = 0; // what are error exit codes?
}
