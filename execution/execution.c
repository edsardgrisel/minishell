/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrisel <egrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 10:36:12 by egrisel           #+#    #+#             */
/*   Updated: 2025/09/09 12:57:37 by egrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

/// @brief Extracts the builtin_type and executes the corresponding builtin,
/// except for BUILTIN_NONE case where it returns 1
/// @param ast_node 
/// @return 
int	built_in_exec(t_ast_node *ast_node)
{
	t_builtin_type	builtin_type;
	if (ast_node->node_type == NODE_COMMAND)
	{
		builtin_type = get_builtin_cmd(ast_node->command_and_args);

	}
}


int	execution(t_ast_node *ast_root)
{
	//single commands only
	built_in_exec(ast_root);
}