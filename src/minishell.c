/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvan-ast <jvan-ast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 13:14:20 by egrisel           #+#    #+#             */
/*   Updated: 2025/10/09 17:53:09 by jvan-ast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "pipex.h"
/// @brief tokens alloced and set, ast calculated and tokens freed after.
/// @param line 
/// @return the abstract syntax tree for exec
t_ast_node	*create_ast(char *line)
{
	t_token		*tokens;
	t_ast_node	*ast;

	tokens = tokenize(line);
	if (tokens == NULL)
		return (NULL);
	ast = parse(tokens);
	cleanup_tokens(tokens);
	if (ast == NULL)
		return (NULL);
	return (ast);
}

/// @brief Reads line and passes it to get_ast, after which line is freed.
/// then ast is passed to execution
/// @return 0 when you want to give another prompt, -1 when error or exit and
/// you want to close the program in main
int	minishell(t_minishell_info *minishell_info)
{
	char		*line;
	t_ast_node	*ast;
	int			result;

	line = readline("minishell$ ");
	if (line == NULL)
		return (perror("Readline returned null. Exiting minishell\n"), -1);
	add_history(line);
	ast = create_ast(line);
	free(line);
	if (ast == NULL)
		return (-1);
	minishell_info->ast = ast;
	pipex_test(ast, 1, 0, *(minishell_info->envp));
	result = execution(minishell_info);
	free_ast(ast);
	return (result);
}
