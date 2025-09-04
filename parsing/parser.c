/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrisel <egrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 15:06:21 by egrisel           #+#    #+#             */
/*   Updated: 2025/09/04 16:42:27 by egrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

t_ast_node	*create_node(t_ast_node_type node_type)
{
	t_ast_node	*node;

	node = ft_calloc(1, sizeof(t_ast_node));
	node->node_type = node_type;
	return (node);
}

int	set_command_and_args(t_token *tokens, int *i)
{
	while (tokens[*i].type == TOKEN_WORD)
}

/*
command = command_name {redirect | argument}
*/
t_ast_node	*parse_command(t_token *tokens, int *i)
{
	t_ast_node	*command_node;

	command_node = create_node(NODE_COMMAND);
	if (set_command_and_args(*command_node, i) == -1)
		return (free(command_node), NULL);
	(void)tokens;
	(void)i;
	return (NULL);
}

/*
executable = {redirect}, command, {redirect}
*/
t_ast_node	*parse_executable(t_token *tokens, int *i)
{
	t_ast_node	*result;
	// skip optional redirect
	result = parse_command(tokens, i);
	return (result);
}

/*
pipeline = executable, {"|" executable}
*/
t_ast_node	*parse_pipeline(t_token *tokens, int *i)
{
	t_ast_node	*left;

	left = parse_executable(tokens, i);
	return (left);
}



t_ast_node	*parse(t_token *tokens)
{
	int	i;
	t_ast_node	*result;

	i = 0;
	result = parse_pipeline(tokens, &i);
	if (result == NULL)
		return (NULL);
	if (tokens[i].type != TOKEN_NONE)
		return (NULL);
	return (result);
}