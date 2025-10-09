/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_cleanup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrisel <egrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 14:00:42 by egrisel           #+#    #+#             */
/*   Updated: 2025/09/24 13:57:14 by egrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>

/// @brief frees as alloced value strings and then frees the whole tokens array
/// @param tokens 
void	cleanup_tokens(t_token *tokens)
{
	int	i;

	i = 0;
	while (tokens[i].type != TOKEN_NONE)
	{
		if (tokens[i].value)
			free(tokens[i].value);
		i++;
	}
	free(tokens);
}

/// @brief Recursively free all ast nodes
/// @param ast 
void	free_ast(t_ast_node *ast)
{
	if (ast->left)
		free_ast(ast->left);
	if (ast->right)
		free_ast(ast->right);
	if (ast->cmd_str)
		free(ast->cmd_str);
	if (ast->heredoc_delim)
		free(ast->heredoc_delim);
	if (ast->redirect_file)
		free(ast->redirect_file);
	free(ast);
	ast = NULL;
}