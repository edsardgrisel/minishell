/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrisel <egrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 15:06:21 by egrisel           #+#    #+#             */
/*   Updated: 2025/09/24 12:42:48 by egrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <stdlib.h>

t_ast_node_type	get_redirect_node_type(t_token *cur_token)
{
	t_ast_node_type	node_type;

	if (cur_token->type == TOKEN_REDIRECT_IN)
		node_type = NODE_REDIRECT_IN;
	else if (cur_token->type == TOKEN_REDIRECT_OUT)
		node_type = NODE_REDIRECT_OUT;
	else if (cur_token->type == TOKEN_REDIRECT_HEREDOC)
		node_type = NODE_REDIRECT_HEREDOC;
	else if (cur_token->type == TOKEN_REDIRECT_APPEND)
		node_type = NODE_REDIRECT_APPEND;
	else
		node_type = NODE_NONE;
	return (node_type);
}

/// @brief Add redirect parent node to the current root.
/// @param root 
/// @param cur_token 
/// @param next_node 
/// @return returns the parent (new root in set_cmd_str())
t_ast_node	*add_redirect_parent_node(
	t_ast_node *root,
	t_token *cur_token,
	t_token *next_node)
{
	t_ast_node		*parent;
	t_ast_node_type	node_type;
	char			*redirect_file;
	char			*heredoc_delim;
	char			*next_node_value;

	next_node_value = ft_strdup(next_node->value);
	heredoc_delim = NULL;
	if (next_node_value == NULL)
		return (NULL);
	node_type = get_redirect_node_type(cur_token);
	if (node_type == NODE_NONE)
		return (free(next_node_value), NULL); // check this case?
	if (node_type == NODE_REDIRECT_HEREDOC)
	{
		redirect_file = NULL;
		heredoc_delim = next_node_value;
	}
	else
		redirect_file = next_node_value;
	parent = create_node(node_type, NULL, redirect_file, heredoc_delim);
	if (parent == NULL)
		return (free(redirect_file), NULL);
	parent->left = root;
	return (parent);
}

t_ast_node	*create_node(
	t_ast_node_type node_type,
	char *cmd_str,
	char *redirect_file,
	char *heredoc_delim
)
{
	t_ast_node	*node;

	node = ft_calloc(1, sizeof(t_ast_node));
	if (node == NULL)
		return (NULL);
	node->node_type = node_type;
	node->cmd_str = cmd_str;
	node->redirect_file = redirect_file;
	node->heredoc_delim = heredoc_delim;
	return (node);
}


// "ls > out.txt -l"

/*
executable = {redirect}, command
*/
t_ast_node	*parse_executable(t_token *tokens, int *i)
{
	t_ast_node	*root;
	t_ast_node	*command_node;

	root = NULL;
	if (tokens[*i].type == TOKEN_REDIRECT_IN ||
		tokens[*i].type == TOKEN_REDIRECT_OUT ||
		tokens[*i].type == TOKEN_REDIRECT_HEREDOC ||
		tokens[*i].type == TOKEN_REDIRECT_APPEND)
	{
		root = add_redirect_parent_node(
			NULL, &(tokens[*i]), &(tokens[++(*i)]));
		if (root == NULL)
			return (free_ast(root), NULL);
		/////// check tihs
		(*i)++;
		////////
	}
	command_node = parse_command(tokens, i);
	if (command_node == NULL)
		return (NULL);
	if (root != NULL)
		root->left = command_node;
	else
		root = command_node;
	return (root);
}

/// @brief will parse the pipe and link the left and right commands
/// if right node happens to be empty, this will be caught in exec as there is
/// no right side to the pipe
/// @param root old root is new left of pipe parent node
/// @param right_node is the node to the right of the pipe parent node
/// @return pipe parent node
static t_ast_node	*add_parent_pipe_node(
	t_ast_node *root,
	t_token *tokens,
	int *i)
{
	t_ast_node	*parent_pipe;
	t_ast_node	*right_node;


	parent_pipe = create_node(NODE_PIPE, NULL, NULL, NULL);
	if (parent_pipe == NULL)
		return (NULL);
	parent_pipe->left = root;
	right_node = parse_executable(tokens, i);
	if (right_node == NULL)
		return (free_ast(parent_pipe), NULL);
	parent_pipe->right = right_node;
	return (parent_pipe);
}

/*
pipeline = executable, {"|" executable}
*/
t_ast_node	*parse_pipeline(t_token *tokens, int *i)
{
	t_ast_node	*root;
	t_ast_node	*parent_pipe;


	root = parse_executable(tokens, i);

	while (tokens[*i].type != TOKEN_NONE)
	{
		if (tokens[*i].type == TOKEN_PIPE)
		{
			(*i)++;
			parent_pipe = add_parent_pipe_node(root, tokens, i);
			if (parent_pipe == NULL)
				return (free_ast(root), NULL);
			root = parent_pipe;
		}
		else
			break;
	}
	return (root);
}
// ["ls", "|", "wc"]


t_ast_node	*parse(t_token *tokens)
{
	int			i;
	t_ast_node	*root;

	i = 0;
	root = parse_pipeline(tokens, &i);
	if (root == NULL)
		return (NULL);
	if (tokens[i].type != TOKEN_NONE)
		return (NULL);
	return (root);
}