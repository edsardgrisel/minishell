/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrisel <egrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 13:14:20 by egrisel           #+#    #+#             */
/*   Updated: 2025/08/27 16:39:30 by egrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

/// @brief tokens alloced and set, ast calculated and tokens freed after.
/// @param line 
/// @return the abstract syntax tree for exec
t_ast	*create_ast(char *line)
{
	t_token	*tokens;

	tokens = tokenize(line);
	if (tokens == NULL)
		return (NULL);

	
	free(tokens);
	return (NULL);
}

/// @brief Reads line and passes it to get_ast, after which line is freed.
/// @return 
int	minishell(char *envp[])
{
	char	*line;
	t_ast	*ast;


	line = readline("minishell$ ");
	if (line == NULL)
		return (perror("readline error."), -1);
	ast = create_ast(line);
	free(line);
	if (ast == NULL)
		return (-1);
	// execution(ast);
	return (0);
}