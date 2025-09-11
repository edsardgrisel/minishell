/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrisel <egrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 10:36:12 by egrisel           #+#    #+#             */
/*   Updated: 2025/09/11 13:55:58 by egrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

/// @brief Extracts the builtin_type and executes the corresponding builtin,
/// except for BUILTIN_NONE case where it returns 1
/// @param ast_node 
/// @return 
int	built_in_exec(t_ast_node *ast_node, t_minishell_info *minishell_info)
{
	t_builtin_type	builtin_type;

	builtin_type = ast_node->builtin_type;
	if (builtin_type == BUILTIN_ECHO)
		exec_echo(ast_node, minishell_info);
	// else if (builtin_type == BUILTIN_CD)
	// 	exec_cd(ast_node, minishell_info);
	// else if (builtin_type == BUILTIN_PWD)
	// 	exec_pwd(ast_node, minishell_info);
	// else if (builtin_type == BUILTIN_EXPORT)
	// 	exec_export(ast_node, minishell_info);
	// else if (builtin_type == BUILTIN_UNSET)
	// 	exec_unset(ast_node, minishell_info);
	else if (builtin_type == BUILTIN_ENV)
		exec_env(minishell_info);
	// else if (builtin_type == BUILTIN_EXIT)
	// 	exec_exit(ast_node, minishell_info);
	// else if (builtin_type == BUILTIN_NONE)
	// 	return (1);
	return (0);

}


int	execution(t_ast_node *ast_root, t_minishell_info *minishell_info)
{
	int	is_not_built_in;
	//single commands only
	is_not_built_in = built_in_exec(ast_root, minishell_info);


	// return success;
	return (0);
}