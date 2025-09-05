/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrisel <egrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 15:06:21 by egrisel           #+#    #+#             */
/*   Updated: 2025/09/05 15:35:41 by egrisel          ###   ########.fr       */
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
executable = {redirect}, command, {redirect}
*/
t_ast_node	*parse_executable(t_token *tokens, int *i)
{
	t_ast_node	*result;
	// skip optional redirect
	result = parse_command(tokens, i);
	// skip optional redirect
	return (result);
}

/*
pipeline = executable, {"|" executable}
*/
t_ast_node	*parse_pipeline(t_token *tokens, int *i)
{
	t_ast_node	*result;

	result = parse_executable(tokens, i);




	return (result);
}
// ["ls", "|", "wc"]


t_ast_node	*parse(t_token *tokens)
{
	int			i;
	t_ast_node	*result;

	i = 0;
	result = parse_pipeline(tokens, &i);
	if (result == NULL)
		return (NULL);
	if (tokens[i].type != TOKEN_NONE)
		return (NULL);
	return (result);
}