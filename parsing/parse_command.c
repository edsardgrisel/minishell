/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrisel <egrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 13:41:12 by egrisel           #+#    #+#             */
/*   Updated: 2025/09/10 14:16:48 by egrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>
#include "libft.h"

/// @brief Gets the t_builtin_type of the command_str and checks if it ends with
/// a space or null terminator. E.g "echo" and "echo " both returh BUILTIN_ECHO
/// @param command_str 
/// @return 
t_builtin_type	get_builtin_type(char *command_str)
{
	if (ft_strncmp(command_str, "echo", 4) == 0 && 
		(command_str[4] == '\0' || command_str[4] == ' '))
		return (BUILTIN_ECHO);
	else if (ft_strncmp(command_str, "cd", 2) == 0 && 
		(command_str[2] == '\0' || command_str[2] == ' '))
		return (BUILTIN_CD);
	else if (ft_strncmp(command_str, "pwd", 3) == 0 && 
		(command_str[3] == '\0' || command_str[3] == ' '))
		return (BUILTIN_PWD);
	else if (ft_strncmp(command_str, "export", 6) == 0 && 
		(command_str[6] == '\0' || command_str[6] == ' '))
		return (BUILTIN_EXPORT);
	else if (ft_strncmp(command_str, "unset", 5) == 0 && 
		(command_str[5] == '\0' || command_str[5] == ' '))
		return (BUILTIN_UNSET);
	else if (ft_strncmp(command_str, "env", 3) == 0 && 
		(command_str[3] == '\0' || command_str[3] == ' '))
		return (BUILTIN_ENV);
	else if (ft_strncmp(command_str, "exit", 4) == 0 && 
		(command_str[4] == '\0' || command_str[4] == ' '))
		return (BUILTIN_EXIT);
	return (BUILTIN_NONE);
}

/// @brief reallocs and appends to_append to the ast_nodes command_and_args and
/// frees the old command_and_args string. In case command_and_args is empty
/// (first call of this function when the token is the command name), strdup 
/// @param result 
/// @param to_append 
/// @return 0 on success, -1 on failure
static int	append_word(t_ast_node *ast_node, char *to_append)
{
	char	*temp;

	if (ast_node->command_and_args == NULL)
	{
		ast_node->command_and_args = ft_strdup(to_append);
		if (ast_node->command_and_args == NULL)
			return (-1);
		ast_node->builtin_type = get_builtin_type(ast_node->command_and_args);
	}
	else
	{
		temp = ft_strjoin_char(ast_node->command_and_args, to_append, ' ');
		if (temp == NULL)
			return (-1);
		free(ast_node->command_and_args);
		ast_node->command_and_args = temp;
	}
	return (0);
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
	t_ast_node	*parent_redirect;

	root = create_node(NODE_COMMAND, NULL, NULL);
	if (root == NULL)
		return (NULL);
	while (tokens[*i].type != TOKEN_NONE && tokens[*i].type != TOKEN_PIPE)
	{
		if (tokens[*i].type == TOKEN_WORD)
		{
			if (append_word(root, tokens[*i].value) == -1)
				return (free(root), NULL);
		}
		else
		{
			parent_redirect = add_redirect_parent_node(
				root, &(tokens[*i]), &(tokens[++(*i)]));
			if (parent_redirect == NULL)
				return (clear_ast(root), NULL);
			root = parent_redirect;
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