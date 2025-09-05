/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrisel <egrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 15:06:21 by egrisel           #+#    #+#             */
/*   Updated: 2025/09/05 16:58:08 by egrisel          ###   ########.fr       */
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
	return (root);
}

static t_ast_node	*add_pipe_parent_node(
	t_ast_node *root,
	t_token *cur_token,
	t_token *next_node)
{
	t_ast_node	*parent;

	parent = create_node(NODE_PIPE, NULL, next_node->value);
	parent->left = root;
	return (parent);
}

/*
pipeline = executable, {"|" executable}
*/
t_ast_node	*parse_pipeline(t_token *tokens, int *i)
{
	t_ast_node	*root;

	root = parse_executable(tokens, i);

	if (tokens[*i].type == TOKEN_PIPE)
	{

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