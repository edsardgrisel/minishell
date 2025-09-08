/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrisel <egrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 13:41:12 by egrisel           #+#    #+#             */
/*   Updated: 2025/09/08 13:25:03 by egrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>
#include "libft.h"

/// @brief reallocs and appends to_append to the ast_nodes command_and_args and
/// frees the old command_and_args string.
/// @param result 
/// @param to_append 
/// @return 0 on success, -1 on failure
static int	append_word(t_ast_node *result, char *to_append)
{
	char	*temp;

	if (result->command_and_args == NULL)
	{
		result->command_and_args = ft_strdup(to_append);
		if (result->command_and_args == NULL)
			return (-1);
	}
	else
	{
		temp = ft_strjoin_char(result->command_and_args, to_append, ' ');
		if (temp == NULL)
			return (-1);
		free(result->command_and_args);
		result->command_and_args = temp;
	}
	return (0);
}
/// @brief Add redirect parent node to the current root.
/// @param root 
/// @param cur_token 
/// @param next_node 
/// @return returns the parent (new root in set_command_and_args())
static t_ast_node	*add_redirect_parent_node(
	t_ast_node *root,
	t_token *cur_token,
	t_token *next_node)
{
	t_ast_node	*parent;
	t_ast_node_type	node_type;

	if (cur_token->type == TOKEN_REDIRECT_IN)
		node_type = NODE_REDIRECT_IN;
	else if (cur_token->type == TOKEN_REDIRECT_OUT)
		node_type = NODE_REDIRECT_OUT;
	else if (cur_token->type == TOKEN_REDIRECT_HEREDOC)
		node_type = NODE_REDIRECT_HEREDOC;
	else if (cur_token->type == TOKEN_REDIRECT_APPEND)
		node_type = NODE_REDIRECT_APPEND;
	parent = create_node(node_type, NULL, next_node->value);
	if (parent == NULL)
		return (NULL);
	parent->left = root;
	return (parent);
}

/// @brief Will loop until the end of tokens or a pipe. It will gather the
/// command and args and any redirects with associated in or outfile and return
/// as an ast. Per loop, WORD's are appended with a space to command_and_args
/// else (redirect case) 
/// @param tokens 
/// @param i 
/// @return 
static t_ast_node	*set_command_and_args(t_token *tokens, int *i)
{
	t_ast_node	*root;
	t_ast_node	*old_root;

	root = create_node(NODE_COMMAND, NULL, NULL);
	old_root = root;
	if (root == NULL)
		return (NULL);
	while (tokens[*i].type != TOKEN_NONE && tokens[*i].type != TOKEN_PIPE)
	{
		if (tokens[*i].type == TOKEN_WORD)
		{
			if (append_word(old_root, tokens[*i].value) == -1)
				return (free(root), NULL);
		}
		else
		{
			root = add_redirect_parent_node(root, &(tokens[*i]), &(tokens[++(*i)]));
			if (root == NULL)
				return (free(root), NULL);
		}
		(*i)++;
	}

	return (root);
}

/*
command = command_name {redirect | argument}
*/
t_ast_node	*parse_command(t_token *tokens, int *i)
{
	return (set_command_and_args(tokens, i));
}