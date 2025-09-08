/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrisel <egrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 15:06:21 by egrisel           #+#    #+#             */
/*   Updated: 2025/09/08 14:05:31 by egrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"



t_ast_node	*create_node(
	t_ast_node_type node_type,
	char *command_and_args,
	char *redirect_file
)
{
	t_ast_node	*node;

	node = ft_calloc(1, sizeof(t_ast_node));
	if (node == NULL)
		return (NULL);
	node->node_type = node_type;
	node->command_and_args = command_and_args;
	node->redirect_file = redirect_file;
	return (node);
}


// "ls > out.txt -l"

/*
executable = {redirect}, command
*/
t_ast_node	*parse_executable(t_token *tokens, int *i)
{
	t_ast_node	*root;
	// skip optional redirect
	root = parse_command(tokens, i);
	if (root == NULL)
		return (NULL);
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


	parent_pipe = create_node(NODE_PIPE, NULL, NULL);
	if (parent_pipe == NULL)
		return (NULL);
	parent_pipe->left = root;
	right_node = parse_executable(tokens, i);
	if (right_node == NULL)
		return (clear_ast(parent_pipe), NULL);
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

	// currently only works for single pipes in pipeline
	if (tokens[*i].type == TOKEN_PIPE)
	{
		(*i)++;
		parent_pipe = add_parent_pipe_node(root, tokens, i);
		if (parent_pipe == NULL)
			return (clear_ast(root), NULL);
		return (parent_pipe);
	}
	else
		return (root);


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