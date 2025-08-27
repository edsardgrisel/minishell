/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrisel <egrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 13:14:20 by egrisel           #+#    #+#             */
/*   Updated: 2025/08/27 14:02:47 by egrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>
#include <stdio.h>

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
}

/// @brief Reads line and passes it to get_ast, after which line is freed.
/// @return 
int	minishell(char *envp[])
{
	char	*line;
	t_ast	*ast;


	line = readline("minishell$ ");
	if (line == NULL)
		return (perror("readline error."), EXIT_FAILURE);
	ast = create_ast(line);
	free(line);
	if (ast == NULL)
		return (EXIT_FAILURE);
	execution(ast);

}